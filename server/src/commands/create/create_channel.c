/*
** EPITECH PROJECT, 2023
** create channel
** File description:
** create_channel
*/

#include "prototypes.h"

void create_new_channel(t_server *server, t_client *client, t_channel *tmp)
{
    char *message = malloc(sizeof(char) * 1024);
    char *temp = malloc(sizeof(char) * 1024);

    add_channel(server, init_channel_struct(server->command_arr[1],
            server->command_arr[2], client->uuid, NULL));
    tmp = server->use_team->channels;
    sprintf(message, "205,%s,%s,%s\n", tmp->uuid, tmp->name,
                tmp->description);
    sprintf(temp, "321,%s,%s,%s", tmp->uuid, tmp->name,
            tmp->description);
    strcat(message, temp);
    dprintf(client->fd, "%s", message);
    for (t_client *tmp_client = server->clients; tmp_client != NULL;
        tmp_client = tmp_client->next)
        if (tmp_client->is_logged == true && tmp_client->fd != client->fd)
            dprintf(tmp_client->fd, "205,%s,%s,%s", tmp->uuid, tmp->name,
                tmp->description);
    server_event_channel_created(server->use_team->uuid, tmp->uuid,
            tmp->name);
}

void create_channel(t_server *server, t_client *client)
{
    t_channel *tmp = NULL;

    if (!server->command_arr[1] || !server->command_arr[2]) {
        dprintf(client->fd, "304");
        return;
    }

    tmp = server->use_team->channels;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->name, server->command_arr[2]) == 0) {
            dprintf(client->fd, "305");
            return;
        }
    }
    create_new_channel(server, client, tmp);
}
