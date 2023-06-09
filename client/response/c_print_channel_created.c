/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_print_channel_created(char **args)
{
    int response = client_print_channel_created(args[1], args[2], args[3]);
    return (0);
}
