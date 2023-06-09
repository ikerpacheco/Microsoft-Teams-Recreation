/*
** EPITECH PROJECT, 2023
** check_logged
** File description:
** check_logged
*/

#include "prototypes.h"

int check_logged(t_server *server, t_client *client)
{
    if (client->is_logged)
        return (1);
    return (0);
}
