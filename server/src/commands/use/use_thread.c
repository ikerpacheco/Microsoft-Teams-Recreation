/*
** EPITECH PROJECT, 2023
** use channel
** File description:
** use_channel
*/

#include "prototypes.h"

void use_thread(t_server *server, t_client *client)
{
    t_thread *tmp = NULL;

    if (server->command_arr[3] == NULL) {
        dprintf(client->fd, "304");
        return;
    }
    tmp = server->use_team->use_channel->threads;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->title, server->command_arr[3]) == 0) {
            server->use = 3;
            server->use_team->use_channel->use_thread = tmp;
            return;
        }
    }
    dprintf(client->fd, "302");
}
