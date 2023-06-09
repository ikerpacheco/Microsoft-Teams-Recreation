/*
** EPITECH PROJECT, 2023
** protocol
** File description:
** protocol
*/

#include "protocol.h"

const protocol_t protocol[] = {
    {"200", &c_event_logged_in},
    {"201", &c_event_logged_out},
    {"202", &c_event_private_message_received},
    {"203", &c_event_thread_reply_received},
    {"204", &c_event_team_created},
    {"205", &c_event_channel_created},
    {"206", &c_event_thread_created},
    {"209", &c_print_user},
    {"208", &c_print_thread},
    {"210", &c_print_users},
    {"211", &c_print_teams},
    {"212", &c_team_print_channels},
    {"213", &c_channel_print_threads},
    {"214", &c_thread_print_replies},
    {"220", &c_private_message_print_messages},
    {"300", &c_error_unknown_team},
    {"301", &c_error_unknown_channel},
    {"302", &c_error_unknown_thread},
    {"303", &c_error_unknown_user},
    {"304", &c_error_unauthorized},
    {"305", &c_error_already_exist},
    {"320", &c_print_team_created},
    {"321", &c_print_channel_created},
    {"322", &c_print_thread_created},
    {"323", &c_print_reply_created},
    {"330", &c_print_subscribed},
    {"331", &c_print_unsubscribed},
    {NULL, NULL}};
