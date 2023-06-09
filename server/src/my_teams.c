/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "prototypes.h"

void sigint_handler(int sig)
{
    (void)sig;
    exit(0);
}

void my_teams(t_server *server)
{

    listen_socket(server->server_fd);
    signal(SIGINT, sigint_handler);
    signal(SIGKILL, sigint_handler);

    while (1) {
        manage_connections(server);
        read_clients_commands(server);
    }
}
