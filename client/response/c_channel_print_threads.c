/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_channel_print_threads(char **args)
{
    long time = strtol(args[3], NULL, strlen(args[3]));
    int response = client_channel_print_threads(args[1], args[2],
                                        (time_t)time, args[4], args[5]);
    return (0);
}
