/*
** EPITECH PROJECT, 2023
** server connections
** File description:
** server_connections
*/

#include "prototypes.h"

void accept_new_connection(t_server *server)
{
    int aux_fd = accept_socket(server->server_fd,
    server->client_addr, sizeof(server->client_addr));
    add_client(server, init_client_struct(aux_fd, NULL, NULL));
    return;
}

void select_socket(int fd, fd_set *set, int max_socket)
{
    int available_fd = 0;

    if ((available_fd = select(max_socket + 1, set, NULL, NULL, NULL)) < 0) {
        perror("Select");
        exit(84);
    }
}

void manage_connections(t_server *server)
{
    server->max_socket = server->server_fd;
    FD_ZERO(&server->sockets_set);
    FD_SET(server->server_fd, &server->sockets_set);

    add_clients_to_set(server);
    select_socket(server->server_fd, &server->sockets_set,
    server->max_socket);

    if (FD_ISSET(server->server_fd, &server->sockets_set))
        accept_new_connection(server);
}
