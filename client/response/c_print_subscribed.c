/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_print_subscribed(char **args)
{
    int response = client_print_subscribed(args[1], args[2]);
    return (0);
}
