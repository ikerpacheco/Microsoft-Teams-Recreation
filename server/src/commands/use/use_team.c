/*
** EPITECH PROJECT, 2023
** use team
** File description:
** use_team
*/

#include "prototypes.h"

void use_team(t_server *server, t_client *client)
{
    t_team *tmp = NULL;

    if (server->command_arr[1] == NULL) {
        dprintf(client->fd, "304");
        return;
    }
    tmp = server->teams;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->name, server->command_arr[1]) == 0) {
            printf("use changed to 1\n");
            server->use = 1;
            server->use_team = tmp;
            return;
        }
    }
    dprintf(client->fd, "300");
}
