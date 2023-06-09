/*
** EPITECH PROJECT, 2023
** Socket Utils
** File description:
** Socket Utils
*/

#include "prototypes.h"

int accept_socket(int fd, struct sockaddr_in client, socklen_t client_len)
{
    int client_fd = 0;

    if ((client_fd = accept
        (fd, (struct sockaddr *)&client, &client_len)) < 0){
        perror("accept failed");
        exit(84);
    }
    return client_fd;
}

void listen_socket(int fd)
{
    if (listen(fd, MAX_CLIENTS) < 0) {
        perror("listen error");
        exit(84);
    }
}

void bind_socket (int fd, struct sockaddr_in name)
{
    if (bind(fd, (struct sockaddr *) &name, sizeof(name)) < 0) {
        perror("bind failed. Error");
        exit(84);
    }
}

int create_socket(int domain, int type, int protocol, char *name)
{
    int fd = 0;

    if ((fd = socket(domain, type, protocol)) == -1) {
        perror(strcat(name, ": Socket error"));
        exit (84);
    }
    return fd;
}
