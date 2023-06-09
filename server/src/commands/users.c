/*
** EPITECH PROJECT, 2023
** users
** File description:
** users
*/

#include "prototypes.h"

void command_users(t_server *server, t_client *client)
{
    t_client *tmp = server->clients;
    char *message = malloc(sizeof(char) * 10048);
    memset(message, 0, 10048);

    if (!client->is_logged) {
        dprintf(client->fd, "304");
        return;
    }
    for (; tmp != NULL; tmp = tmp->next) {
        strcat(message, "210,");
        strcat(message, tmp->uuid);
        strcat(message, ",");
        strcat(message, tmp->username);
        strcat(message, ",");
        strcat(message, tmp->is_logged ? "1" : "0");
        strcat(message, "\n");
    }
    dprintf(1, "%s", message);
    dprintf(client->fd, "%s", message);
}
