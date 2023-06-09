/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** channel
*/

#include "../include/structs.h"
#include "../include/prototypes.h"

t_message *init_message_struct(char *body, char *user_uuid, char *uuid)
{
    t_message *message = malloc(sizeof(t_message));
    uuid_t tmp_uuid;


    if (uuid == NULL) {
        uuid_generate(tmp_uuid);
        message->uuid = malloc((sizeof(uuid_t) * 2) + 5);
        uuid_parse(message->uuid, tmp_uuid);
    } else {
        message->uuid = strdup(uuid);
    }
    time(&message->creation_time);
    message->body = strdup(body);
    message->user_uuid = strdup(user_uuid);
    message->next = NULL;
    return (message);
}

void add_message(t_chats *chats, t_message *new_message)
{
    t_message *temp = chats->messages;

    if (!temp) {
        chats->messages = new_message;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_message;
}

t_message *get_message(t_chats *chats, char *uuid)
{
    t_message *temp = chats->messages;

    while (temp != NULL) {
        if (temp->uuid == uuid)
            return (temp);
        temp = temp->next;
    }
    printf("no message with uuid: (%s) found", uuid);
    return (NULL);
}
