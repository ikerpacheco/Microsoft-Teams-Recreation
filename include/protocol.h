/*
** EPITECH PROJECT, 2023
** protocol
** File description:
** protocol
*/

#include "structs.h"
#include "../libs/myteams/logging_client.h"
#include "../libs/myteams/logging_server.h"
#include "prototypes.h"

#pragma once

typedef struct protocol_s {
    char *code;
    int (*func)(char **);
} protocol_t;

extern const protocol_t protocol[];
int c_event_logged_in(char **args);
int c_event_logged_out(char **args);
int c_event_private_message_received(char **args);
int c_event_thread_reply_received(char **args);
int c_event_team_created(char **args);
int c_event_channel_created(char **args);
int c_event_thread_created(char **args);
int c_print_users(char **args);
int c_print_user(char **args);
int c_print_teams(char **args);
int c_team_print_channels(char **args);
int c_channel_print_threads(char **args);
int c_thread_print_replies(char **args);
int c_private_message_print_messages(char **args);
int c_error_unknown_team(char **args);
int c_error_unknown_channel(char **args);
int c_error_unknown_thread(char **args);
int c_error_unknown_user(char **args);
int c_error_unauthorized(char **args);
int c_error_already_exist(char **args);
int c_error_print_user(char **args);
int c_error_print_team(char **args);
int c_error_print_channel(char **args);
int c_error_print_thread(char **args);
int c_print_team_created(char **args);
int c_print_channel_created(char **args);
int c_print_thread_created(char **args);
int c_print_reply_created(char **args);
int c_print_subscribed(char **args);
int c_print_unsubscribed(char **args);
int c_print_thread(char **args);