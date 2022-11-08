#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>

#define SAFE(func, call) \
    if ((call) < 0) {    \
        perror(func);    \
        exit(1);         \
    }

int main() {
    sockaddr_un name;
    int sock_fd;
    SAFE("socket", sock_fd = socket(AF_UNIX, SOCK_STREAM, 0))
    memset(&name, 0, sizeof(name));
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, "123", sizeof(name.sun_path) - 1);
    SAFE("connect", connect(sock_fd, (sockaddr*)&name, sizeof(name)))
    int block_flag;
    std::cout << "setup" << std::endl;
    read(sock_fd, &block_flag, sizeof(block_flag));

    std::cout << "ready to work" << std::endl;
    std::size_t a;
    for (size_t i = 0; i < 500000000; ++i)
        ++a;
        
    std::cout << "calculated all" << std::endl;
    write(sock_fd, &a, sizeof(a));
}