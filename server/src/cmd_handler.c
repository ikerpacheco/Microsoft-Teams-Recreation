/*
** EPITECH PROJECT, 2023
** Handle commands
** File description:
** Handle commands
*/

#include "prototypes.h"
#include "commands.h"

void pass_args(t_server *server, t_client *client, char *command)
{
    server->command_arr = get_client_command(command);
}

void check_command(t_server *server, t_client *client)
{
    char *command = malloc(sizeof(char) * 1024);

    if (FD_ISSET(client->fd, &server->sockets_set)) {
        memset(command, '\0', 1024);
        if (read(client->fd, command, 1024) == 0) {
            close(client->fd);
            FD_CLR(client->fd, &server->sockets_set);
            client->fd = 0;
        } else {
            command = clean_str(command);
            pass_args(server, client, command);
            handle_command(server, client);
        }
    }
}

void read_clients_commands(t_server *server)
{
    t_client *tmp;

    if (server->clients == NULL) {
        printf("es null\n");
        return;
    }

    for (tmp = server->clients; tmp != NULL; tmp = tmp->next) {
        check_command(server, tmp);
    }
}

void handle_command(t_server *server, t_client *client)
{
    int n = 0;

    if (!strcmp(server->command_arr[0], ""))
        return;
    for (n = 0; commands[n].name != NULL; n++) {
        if (strcmp(server->command_arr[0], commands[n].name) == 0) {
            commands[n].func(server, client);
            return;
        }
    }
    dprintf(client->fd, "500 Unknown command.\n");
}
