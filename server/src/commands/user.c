/*
** EPITECH PROJECT, 2023
** users
** File description:
** users
*/

#include "prototypes.h"

void command_user(t_server *server, t_client *client)
{
    t_client *tmp = server->clients;

    if (!client->is_logged) {
        dprintf(client->fd, "304");
        return;
    }
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->username, server->command_arr[1]) == 0) {
            dprintf(client->fd, "209,%s,%s,%s", tmp->uuid, tmp->username,
                tmp->is_logged ? "1" : "0");
            return;
        }
    }
    dprintf(client->fd, "303");
}
