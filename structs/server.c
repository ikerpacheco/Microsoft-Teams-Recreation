/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "structs.h"
#include "prototypes.h"

t_server *init_server_struct(int ac, char **av)
{
    t_server *server = malloc(sizeof(t_server));

    error_handling(ac, av);
    server->path = ".";
    server->server_fd = create_socket(AF_INET, SOCK_STREAM, 0, "Server");
    server->client_fd = 0;
    server->data_fd = 0;
    server->client_addr = initialize_struct_data(0, server->client_addr);
    server->data_addr = initialize_struct_data(0, server->data_addr);
    server->server_addr = initialize_struct_data(
                            atoi(av[1]), server->server_addr);

    server->clients = NULL;
    server->teams = NULL;

    bind_socket(server->server_fd, server->server_addr);
    return (server);
}
