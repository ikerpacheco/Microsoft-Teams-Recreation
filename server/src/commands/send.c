/*
** EPITECH PROJECT, 2023
** logout
** File description:
** logout
*/

#include "prototypes.h"

void handle_message(t_server *server, t_client *sender, t_client *receiver)
{
    t_chats *temp_chat = NULL;

    if (!(temp_chat = get_chat(sender, receiver->uuid))) {
        printf("no chat found, creating new one\n");
        add_chat(sender, init_chats_struct(NULL, sender->uuid));
        temp_chat = sender->chats;
    }
    printf("sending message between user: %s and user: %s\n", sender->username,
            receiver->username);
    add_message(temp_chat, init_message_struct(server->command_arr[2],
                sender->uuid, NULL));
    dprintf(receiver->fd, "202,%s,%s,%s", receiver->uuid, sender->uuid,
            server->command_arr[2]);
    server_event_private_message_sended(sender->uuid, receiver->uuid,
                                        server->command_arr[2]);
    return;
}

void command_send(t_server *server, t_client *client)
{
    t_client *tmp = NULL;

    if (!server->command_arr[1] || !server->command_arr[2]) {
        dprintf(client->fd, "304");
        return;
    }
    for (tmp = server->clients; tmp != NULL; tmp = tmp->next) {
        printf("uuid: %s\n", tmp->uuid);
        printf("command_arr[1]: %s\n", server->command_arr[1]);
        if (strcmp(tmp->uuid, server->command_arr[1]) == 0) {
            handle_message(server, client, tmp);
        }
    }
}
