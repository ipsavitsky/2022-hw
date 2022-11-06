#include "scheduling/annealing.hpp"

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <functional>
#include <iostream>
#include <random>

annealing::annealing(std::shared_ptr<solution> res,
                     std::vector<std::shared_ptr<operation>> opers,
                     std::shared_ptr<temperature> temp)
    : operations(opers), t(temp), cur_best(res) {
    cur_best->generate_approximation();
    std::cout << dynamic_cast<time_diagram*>(cur_best.get())->stringify();
    std::cout << cur_best->calculate_target_function() << std::endl;
    best_target_func = cur_best->calculate_target_function();
}

void annealing::run_routine() {
    int sock_fd;
    sockaddr_un reduction_addr;
    memset(&reduction_addr, 0, sizeof(reduction_addr));
    reduction_addr.sun_family = AF_UNIX;
    strcpy(reduction_addr.sun_path, "123");
    int servlen =
        strlen(reduction_addr.sun_path) + sizeof(reduction_addr.sun_family);
    int sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    connect(sock_fd, (sockaddr*)&reduction_addr, servlen);
    std::cout << getpid() << ": connected to socket" << std::endl;

    std::random_device r;
    auto rand_oper =
        std::bind(std::uniform_int_distribution<>(0, operations.size() - 1),
                  std::default_random_engine(r()));
    auto annealing_prob = std::bind(std::uniform_real_distribution<>(0, 1),
                                    std::default_random_engine(r()));
    std::size_t useless_iteration = 0;
    std::size_t temp_it = 5;
    for (uint64_t i = 0; i < temp_it; ++i) {
        std::shared_ptr<operation> op = operations[rand_oper()];
        std::shared_ptr<solution> new_solution = op->eval(cur_best);
        std::size_t new_target_func = new_solution->calculate_target_function();
        int64_t f_delta = new_target_func - best_target_func;
        if (f_delta < 0) {
            std::swap(cur_best, new_solution);
            best_target_func = new_target_func;
            useless_iteration = 0;
        } else {
            ++useless_iteration;
            double temp_cutoff =
                std::exp(static_cast<double>(-f_delta) / t->get_temp());
            double test = annealing_prob();
            if (test <= temp_cutoff) {
                std::swap(cur_best, new_solution);
                best_target_func = new_target_func;
            }
        }
    }
    std::cout << getpid() << ": got " << best_target_func << std::endl;
    write(sockfd, &best_target_func, sizeof(best_target_func));
    close(sockfd);
    exit(1);
}

void annealing::anneal() {
    std::size_t iteration = 0;
    while (true) {
        uint32_t N_PROC = 2;
        std::vector<pid_t> workers;

        for (uint32_t i = 0; i < N_PROC; ++i) {
            pid_t fk_pid = fork();
            if (fk_pid == 0) {
                run_routine();
            }
            std::cout << "spawned " << fk_pid << std::endl;
            workers.push_back(fk_pid);
        }

        int sock_fd;
        sockaddr_un con_sock;

        sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
        memset(&con_sock, 0, sizeof(con_sock));
        con_sock.sun_family = AF_UNIX;
        strcpy(con_sock.sun_path, "123");
        socklen_t servelen =
            strlen(con_sock.sun_path) + sizeof(con_sock.sun_family);
        bind(sock_fd, (sockaddr*)&con_sock, servelen);
        // change 5 to an acceptable number later
        listen(sock_fd, 5);

        std::vector<decltype(best_target_func)> reduction_times;
        for (pid_t wk : workers) {
            sockaddr_un client_sock;
            socklen_t clilen = sizeof(client_sock);
            int cli_fd;
            cli_fd = accept(sock_fd, (sockaddr*)&client_sock, &clilen);
            decltype(best_target_func) best_func;
            read(cli_fd, &best_func, sizeof(best_func));
            reduction_times.push_back(best_func);
            close(cli_fd);
            wait(0);
        }

        for(std::size_t time : reduction_times) {
            std::cout << "got time to reduce: " << time << std::endl;
        }

        close(sock_fd);

        break;
        // if (useless_iteration > 100) {
        //     break;
        // }

        if (iteration % 10000) {
            std::cout << "cur_targ_func = "
                      << cur_best->calculate_target_function() << std::endl;
        }

        ++iteration;
        t->eval(iteration);
    }
}

std::shared_ptr<solution> annealing::get_solution() {
    return cur_best;
}