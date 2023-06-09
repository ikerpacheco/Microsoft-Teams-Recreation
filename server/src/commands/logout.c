/*
** EPITECH PROJECT, 2023
** logout
** File description:
** logout
*/

#include "prototypes.h"

void command_logout(t_server *server, t_client *client)
{
    if (client->is_logged) {
        client->is_logged = false;
        dprintf(client->fd, "201,%s,%s", client->uuid, client->username);
        server_event_user_logged_out(client->uuid);
        return;
    }
    dprintf(client->fd, "304");
}
