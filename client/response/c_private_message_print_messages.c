/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_private_message_print_messages(char **args)
{
    long time = strtol(args[3], NULL, strlen(args[3]));
    int response = client_private_message_print_messages(args[1],
        (time_t)time, args[3]);
    return (0);
}
