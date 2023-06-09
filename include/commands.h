/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "structs.h"
#include "prototypes.h"

#pragma once

typedef struct commands_s {
    char *name;
    void (*func)(t_server *server, t_client *client);
} commands_t;

extern const commands_t commands[];

void command_help(t_server *server, t_client *client);
void command_login(t_server *server, t_client *client);
void command_logout(t_server *server, t_client *client);
void command_users(t_server *server, t_client *client);
void command_user(t_server *server, t_client *client);
void command_send(t_server *server, t_client *client);
// void command_messages(t_server *server, t_client *client);
// void command_subscribe(t_server *server, t_client *client);
// void command_subscribed(t_server *server, t_client *client);
// void command_unsubscribe(t_server *server, t_client *client);
void command_use(t_server *server, t_client *client);
void command_create(t_server *server, t_client *client);
void command_list(t_server *server, t_client *client);
// void command_info(t_server *server, t_client *client);
