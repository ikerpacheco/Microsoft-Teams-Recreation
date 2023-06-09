/*
** EPITECH PROJECT, 2023
** create
** File description:
** create
*/

#include "prototypes.h"


void create_new_team(t_server *server, t_client *client, t_team *tmp)
{
    char *message = malloc(sizeof(char) * 1024);
    char *temp = malloc(sizeof(char) * 1024);

    add_team(server, init_team_struct(server->command_arr[1],
            server->command_arr[2], client->uuid, NULL));
    tmp = server->teams;
    sprintf(message, "204,%s,%s,%s\n", tmp->uuid, tmp->name,
                tmp->description);
    sprintf(temp, "320,%s,%s,%s", tmp->uuid, tmp->name,
            tmp->description);
    strcat(message, temp);
    dprintf(client->fd, "%s", message);
    for (t_client *tmp_client = server->clients; tmp_client != NULL;
        tmp_client = tmp_client->next)
        if (tmp_client->is_logged == true && tmp_client->fd != client->fd)
            dprintf(tmp_client->fd, "204,%s,%s,%s", tmp->uuid, tmp->name,
                tmp->description);
    server_event_team_created(tmp->uuid, tmp->name, client->uuid);
}

void create_team(t_server *server, t_client *client)
{
    t_team *tmp = NULL;

    if (!server->command_arr[1] || !server->command_arr[2]) {
        dprintf(client->fd, "304");
        return;
    }

    tmp = server->teams;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->name, server->command_arr[1]) == 0) {
            dprintf(client->fd, "305");
            return;
        }
    }
    create_new_team(server, client, tmp);
}
