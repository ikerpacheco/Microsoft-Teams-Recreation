/*
** EPITECH PROJECT, 2023
** client.c
** File description:
** client
*/

#include "../include/structs.h"
#include "../include/prototypes.h"

t_client *init_client_struct(int fd, char *username, char *uuid)
{
    t_client *client = malloc(sizeof(t_client));
    uuid_t tmp_uuid;

    if (uuid == NULL) {
        uuid_generate(tmp_uuid);
        client->uuid = malloc((sizeof(uuid_t) * 2) + 5);
        uuid_unparse(tmp_uuid, client->uuid);
    } else {
        client->uuid = strdup(uuid);
    }
    client->fd = fd;
    client->username = username;
    client->is_logged = false;
    client->is_passive = 0;
    client->port = 0;
    client->chats = NULL;
    client->next = NULL;
    return (client);
}

void free_client(t_client *client)
{
    if (client->username != NULL)
        free(client->username);
    free(client);
}

t_client *get_client(t_client *client, char *uuid)
{
    t_client *temp = client;

    while (temp != NULL) {
        if (temp->uuid == uuid) {
            return (temp);
        }
        temp = temp;
    }
    if (temp == NULL) {
        printf("error client not found");
    }
    return (NULL);
}

void free_all_clients(t_client *client, char *del_uuid)
{
    t_client *temp = client;
    t_client *del;

    while (temp != NULL) {
        if (temp->uuid == del_uuid) {
            del = temp;
            temp = temp->next;
            free_client(del);
            break;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("error client not found");
    }
    temp->next = temp->next->next;
}

void add_client(t_server *server, t_client *new_client)
{
    t_client *temp = server->clients;

    if (!temp) {
        server->clients = new_client;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_client;
}
