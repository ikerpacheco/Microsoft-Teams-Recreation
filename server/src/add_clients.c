/*
** EPITECH PROJECT, 2023
** add_clients
** File description:
** add_clients
*/

#include "prototypes.h"

void check_available_fd(t_server *server, int client_fd)
{
    if (client_fd > 0) {
        FD_SET(client_fd, &server->sockets_set);
        if (client_fd > server->max_socket)
            server->max_socket = client_fd;
    }
}

void add_clients_to_set(t_server *server)
{
    t_client *tmp = server->clients;

    if (tmp == NULL)
        return;

    for (; tmp != NULL; tmp = tmp->next) {
        check_available_fd(server, tmp->fd);
    }
}
