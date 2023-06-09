/*
** EPITECH PROJECT, 2023
** create
** File description:
** create
*/

#include "prototypes.h"

void command_create(t_server *server, t_client *client)
{
    if (client->is_logged == false) {
        dprintf(client->fd, "304");
        return;
    }

    switch (server->use) {
        case 0:
            create_team(server, client);
            return;
        case 1:
            create_channel(server, client);
            return;
        case 2:
            create_thread(server, client);
            return;
        case 3:
            return;
        default:
            return;
    }
}
