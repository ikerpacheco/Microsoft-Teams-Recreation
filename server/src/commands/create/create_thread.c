/*
** EPITECH PROJECT, 2023
** create thread
** File description:
** create_thread
*/

#include "prototypes.h"

void create_new_thread(t_server *server, t_client *client, t_thread *tmp)
{
    char *message = malloc(sizeof(char) * 1024);
    char *temp = malloc(sizeof(char) * 1024);

    add_thread(server, init_thread_struct(server->command_arr[1],
                server->command_arr[2], client->uuid, NULL));
    tmp = server->use_team->use_channel->threads;
    sprintf(message, "206,%s,%s,%ld,%s,%s", tmp->uuid, client->uuid,
                tmp->creation_time, tmp->title, tmp->message);
    sprintf(temp, "322,%s,%s,%ld,%s,%s", tmp->uuid, client->uuid,
                tmp->creation_time, tmp->title, tmp->message);
    strcat(message, temp);
    dprintf(client->fd, "%s", message);
    for (t_client *tmp_client = server->clients; tmp_client != NULL;
        tmp_client = tmp_client->next)
        if (tmp_client->is_logged == true && tmp_client->fd != client->fd)
            dprintf(client->fd, "206,%s,%s,%ld,%s,%s", tmp->uuid, client->uuid,
                tmp->creation_time, tmp->title, tmp->message);
    server_event_thread_created(server->use_team->use_channel->uuid,
            tmp->uuid, client->uuid, tmp->title,
            tmp->message);
}

void create_thread(t_server *server, t_client *client)
{
    t_thread *tmp = NULL;

    if (server->command_arr[2] == NULL) {
        dprintf(client->fd, "304");
        return;
    }

    tmp = server->use_team->use_channel->threads;
    for (; tmp != NULL; tmp = tmp->next) {
        if (strcmp(tmp->title, server->command_arr[2]) == 0) {
            dprintf(client->fd, "305");
            return;
        }
    }
    create_new_thread(server, client, tmp);
}
