/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** channel
*/

#include "../include/structs.h"
#include "../include/prototypes.h"

t_channel *init_channel_struct(char *name, char *description,
char *user_uuid, char *uuid)
{
    t_channel *channel_struct = malloc(sizeof(t_channel));
    uuid_t tmp_uuid;

    if (uuid == NULL) {
        uuid_generate(tmp_uuid);
        channel_struct->uuid = malloc((sizeof(uuid_t) * 2) + 5);
        uuid_unparse(tmp_uuid, channel_struct->uuid);
    } else {
        channel_struct->uuid = strdup(uuid);
    }
    channel_struct->name = (strlen(name) < MAX_NAME_LENGTH) ? strdup(name)
    : "";
    time(&channel_struct->creation_time);
    channel_struct->description =
    (strlen(description) < MAX_DESCRIPTION_LENGTH) ? strdup(description) : "";
    channel_struct->threads = NULL;
    channel_struct->next = NULL;
    channel_struct->use_thread = NULL;

    return (channel_struct);
}

void free_channel(t_channel *channel)
{
    if (channel->name != NULL)
        free(channel->name);
    if (channel->description != NULL)
        free(channel->description);
    free(channel);
}

void add_channel(t_server *server, t_channel *new_channel)
{
    t_channel *temp = server->use_team->channels;

    if (!temp) {
        server->use_team->channels = new_channel;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_channel;
}

t_channel *get_channel(t_channel *channel, char *uuid)
{
    t_channel *temp = channel;

    while (temp != NULL) {
        if (temp->uuid == uuid) {
            return (temp);
        }
        temp = temp;
    }
    if (temp == NULL) {
        printf("error channel not found");
    }
    return (NULL);
}
