/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_error_unknown_channel(char **args)
{
    int response = client_error_unknown_channel(args[1]);
    return (0);
}
