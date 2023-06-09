/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** channel
*/

#include "../include/structs.h"
#include "../include/prototypes.h"

t_chats *init_chats_struct(char *uuid, char *user_uuid)
{
    t_chats *chats_struct = malloc(sizeof(t_chats));
    uuid_t tmp_uuid;

    if (uuid == NULL) {
        uuid_generate(tmp_uuid);
        chats_struct->uuid = malloc((sizeof(uuid_t) * 2) + 5);
        uuid_unparse(tmp_uuid, chats_struct->uuid);
    } else {
        chats_struct->uuid = strdup(uuid);
    }
    chats_struct->messages = NULL;
    chats_struct->user_uuid = strdup(user_uuid);
    chats_struct->next = NULL;

    return (chats_struct);
}

void free_chats(t_chats *chats)
{
    if (chats->user_uuid != NULL)
        free(chats->user_uuid);
    free(chats);
}

t_chats *get_chat(t_client *client, char *user_uuid)
{
    t_chats *temp = client->chats;

    if (!temp) {
        return (temp);
    }
    while (!temp) {
        printf("chat with receiveir: (%s) found\n", temp->user_uuid);
        printf("chat with sender: (%s) found\n", user_uuid);
        if (temp->user_uuid == user_uuid)
            return (temp);
        temp = temp->next;
    }
    printf("no chat with user with uuid: (%s) found\n", user_uuid);
    return (NULL);
}

void add_chat(t_client *client, t_chats *new_chat)
{
    t_chats *temp = client->chats;

    if (!temp) {
        client->chats = new_chat;
        return;
    }
    while (!client->next) {
        temp = temp->next;
    }
    temp->next = new_chat;
}
