/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_print_reply_created(char **args)
{
    long time = strtol(args[3], NULL, strlen(args[3]));
    int response = client_print_reply_created(args[1], args[2],
                                            (time_t)time, args[4]);
    return (0);
}
