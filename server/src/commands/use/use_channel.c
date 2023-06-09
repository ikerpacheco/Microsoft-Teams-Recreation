/*
** EPITECH PROJECT, 2023
** use channel
** File description:
** use_channel
*/

#include "prototypes.h"

void use_channel(t_server *server, t_client *client)
{
    t_channel *tmp = NULL;

    if (server->command_arr[2] == NULL) {
        dprintf(client->fd, "304");
        return;
    }
    tmp = server->use_team->channels;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->name, server->command_arr[2]) == 0) {
            server->use = 2;
            server->use_team->use_channel = tmp;
            return;
        }
    }
    dprintf(client->fd, "301");
}
