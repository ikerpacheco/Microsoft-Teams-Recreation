/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_team_print_channels(char **args)
{
    int response = client_team_print_channels(args[1], args[2], args[3]);
    return (0);
}
