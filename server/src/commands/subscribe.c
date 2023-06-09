/*
** EPITECH PROJECT, 2023
** subscribe command
** File description:
** subscribe
*/

#include "prototypes.h"

void command_subscribe(t_server *server, t_client *client)
{
    t_team *tmp = NULL;

    if (client->is_logged == false) {
        dprintf(client->fd, "304");
        return;
    }
    if (server->command_arr[1] == NULL || server->use != 0) {
        dprintf(client->fd, "304");
        return;
    }
    tmp = server->teams;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->name, server->command_arr[1]) == 0) {
            add_subscriber(tmp, client);
            return;
        }
    }
}