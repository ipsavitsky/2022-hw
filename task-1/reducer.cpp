#include <sys/socket.h>
#include <sys/un.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <vector>

#define SAFE(func, call) \
    if ((call) < 0) {    \
        perror(func);    \
        exit(1);         \
    }

void do_nothing(int s) {}

void handle_client(int wk_fd) {
    signal(SIGUSR1, do_nothing);
    pause();
    std::cout << getpid() << ": dispathched" << std::endl;
    int flag = 100;
    write(wk_fd, &flag, sizeof(flag));
    size_t a;
    read(wk_fd, &a, sizeof(a));
    exit(1);
}

int main() {
    sockaddr_un name;
    int sock_fd;
    unlink("123");
    SAFE("socket", sock_fd = socket(AF_UNIX, SOCK_STREAM, 0))
    memset(&name, 0, sizeof(name));
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, "123", sizeof(name.sun_path) - 1);
    SAFE("bind", bind(sock_fd, (sockaddr*)&name, sizeof(name)))
    SAFE("listen", listen(sock_fd, 20))
    int cur_num_of_workers = 0;
    std::vector<pid_t> fk_threadpool;
    while (cur_num_of_workers < 10) {
        int loc_fd;
        SAFE("accept", loc_fd = accept(sock_fd, NULL, NULL))
        pid_t fk = fork();
        if (fk == 0) {
            handle_client(loc_fd);
        }
        fk_threadpool.push_back(fk);
        ++cur_num_of_workers;
    }

    // THIS IS BAD
    sleep(1);
    signal(SIGUSR1, SIG_IGN);
    kill(0, SIGUSR1);

    for (int i = 0; i < fk_threadpool.size(); ++i) {
        wait(0);
    }
}