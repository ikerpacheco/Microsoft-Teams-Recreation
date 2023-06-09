/*
** EPITECH PROJECT, 2023
** B-NWP-400-BAR-4-1-myftp-sebastia.gomez-dolc
** File description:
** server
*/

#include "prototypes.h"
#include "protocol.h"
#include "../libs/myteams/logging_client.h"
#include "../libs/myteams/logging_server.h"

void main_loop_ext(t_client *client, fd_set fds, int sockfd, char *temp)
{
    if (FD_ISSET(STDIN_FILENO, &fds)){
        memset(temp, '\0', 5024);
        read(0, temp, 5024);
        send(client->fd, temp, 5024, 0);
    } else if (FD_ISSET(sockfd, &fds))
        check_response(client);
}

void main_loop(t_client *client)
{
    fd_set fds;
    int sockfd = client->fd;
    char *temp = malloc(sizeof(char) * 5024);

    while (1) {
        FD_ZERO(&fds);
        FD_SET(STDIN_FILENO, &fds);
        FD_SET(sockfd, &fds);
        (select(sockfd + 1, &fds, NULL, NULL, NULL) == -1) ? exit(84) : 0;
        main_loop_ext(client, fds, sockfd, temp);
    }
}

t_client *create_client(char *ip, int port, t_client *client)
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    client = init_client_struct(fd, NULL, NULL);
    struct sockaddr_in server_addr = {0};
    struct hostent *info;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(fd, (struct sockaddr *)&server_addr,
        sizeof(server_addr)) == -1) {
        perror("connect failed");
        exit (84);
    }
    return client;
}

int main (int ac, char **av)
{
    error_handling(ac, av);
    t_client *client = create_client(av[1], atoi(av[2]), client);
    signal(SIGINT, handle_signal_action);
    main_loop(client);
    close(client->fd);
}
