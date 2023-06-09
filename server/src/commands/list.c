/*
** EPITECH PROJECT, 2023
** command list
** File description:
** list
*/

#include "prototypes.h"

void list_threads(t_server *server, t_client *client)
{
    t_thread *tmp = server->use_team->use_channel->threads;
    char *final_str = malloc(sizeof(char) * 5024);
    memset(final_str, 0, 5024);
    char *tmp_str = malloc(sizeof(char) * 512);

    for (; tmp != NULL; tmp = tmp->next) {
        memset(tmp_str, 0, 512);
        sprintf(tmp_str, "213,%s,%s,%ld,%s,%s\n", tmp->uuid, tmp->user_uuid,
                tmp->creation_time ,tmp->title, tmp->message);
        strcat(final_str, tmp_str);
    }
    dprintf(client->fd, "%s", final_str);
}

void list_channels(t_server *server, t_client *client)
{
    t_channel *tmp = server->use_team->channels;
    char *final_str = malloc(sizeof(char) * 5024);
    memset(final_str, 0, 5024);
    char *tmp_str = malloc(sizeof(char) * 512);

    for (; tmp != NULL; tmp = tmp->next) {
        memset(tmp_str, 0, 512);
        sprintf(tmp_str, "212,%s,%s,%s\n", tmp->uuid,
                tmp->name, tmp->description);
        strcat(final_str, tmp_str);
    }
    dprintf(client->fd, "%s", final_str);
}

void list_teams(t_server *server, t_client *client)
{
    t_team *tmp = server->teams;
    char *final_str = malloc(sizeof(char) * 5024);
    memset(final_str, 0, 5024);
    char *tmp_str = malloc(sizeof(char) * 512);

    for (; tmp != NULL; tmp = tmp->next) {
        memset(tmp_str, 0, 512);
        sprintf(tmp_str, "211,%s,%s,%s\n", tmp->uuid,
                tmp->name, tmp->description);
        strcat(final_str, tmp_str);
    }
    dprintf(client->fd, "%s", final_str);
}

void choose_list(t_server *server, t_client *client)
{
    int len = arr_len(server->command_arr);

    switch (server->use) {
        case 0:
            list_teams(server, client);
            return;
        case 1:
            list_channels(server, client);
            return;
        case 2:
            list_threads(server, client);
            return;
        case 3:
            return;
        default:
            return;
    }
}

void command_list(t_server *server, t_client *client)
{
    if (client->is_logged == false) {
        dprintf(client->fd, "304");
        return;
    }
    choose_list(server, client);
}
