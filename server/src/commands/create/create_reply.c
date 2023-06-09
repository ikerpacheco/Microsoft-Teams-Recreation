/*
** EPITECH PROJECT, 2023
** reply
** File description:
** create_reply
*/

#include "prototypes.h"

void create_reply(t_server *server, t_client *client)
{
    t_reply *new_reply = malloc(sizeof(t_reply));
    t_reply *tmp = NULL;

    if (server->command_arr[4] == NULL) {
        dprintf(client->fd, "304");
        return;
    }
    new_reply->title = strdup(server->command_arr[4]);
    new_reply->body = strdup(server->command_arr[5]);
    new_reply->author = strdup(client->username);
    new_reply->next = NULL;
    if (server->use_team->use_channel->use_thread->replies == NULL) {
        server->use_team->use_channel->use_thread->replies = new_reply;
        return;
    }
    tmp = server->use_team->use_channel->use_thread->replies;
    for (; tmp->next != NULL; tmp = tmp->next);
    tmp->next = new_reply;
    dprintf(client->fd, "200");
}