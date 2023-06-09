/*
** EPITECH PROJECT, 2023
** login
** File description:
** login
*/

#include "prototypes.h"

void log_client(t_client *client, char *username)
{
    client->is_logged = true;
    client->username = strdup(username);
    dprintf(client->fd, "200,%s,%s", client->uuid, client->username);
    server_event_user_created(client->uuid, client->username);
    server_event_user_logged_in(client->uuid);
}

void command_login(t_server *server, t_client *client)
{
    char *username = strdup(server->command_arr[1]);
    t_client *tmp = server->clients;

    if (client->is_logged) {
        dprintf(client->fd, "304");
        return;
    }

    for (; tmp != NULL; tmp = tmp->next) {
        if (tmp->is_logged && tmp->username != NULL &&
            strcmp(tmp->username, username) == 0) {
            client->is_logged = true;
            client->username = strdup(username);
            dprintf(client->fd, "200,%s,%s", client->uuid, client->username);
            server_event_user_logged_in(client->uuid);
            return;
        }
    }
    log_client(client, username);
}
