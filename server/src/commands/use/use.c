/*
** EPITECH PROJECT, 2023
** use command
** File description:
** use
*/

#include "prototypes.h"

void choose_use(t_server *server, t_client *client)
{
    int len = arr_len(server->command_arr);

    switch (len) {
        case 1:
            server->use = 0;
            server->use_team = NULL;
            return;
        case 2:
            use_team(server, client);
            return;
        case 3:
            use_channel(server, client);
            return;
        case 4:
            use_thread(server, client);
            return;
        default:
            break;
    }
}

void command_use(t_server *server, t_client *client)
{
    if (client->is_logged == false) {
        dprintf(client->fd, "304");
        return;
    }
    choose_use(server, client);
}
