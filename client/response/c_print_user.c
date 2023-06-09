/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_print_user(char **args)
{
    int response = client_print_user(args[1], args[2], atoi(args[3]));
    return (0);
}
