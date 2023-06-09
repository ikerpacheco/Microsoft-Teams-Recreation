/*
** EPITECH PROJECT, 2023
** PASV command
** File description:
** PASV command
*/

#include "prototypes.h"

void command_help(t_server *server, t_client *client)
{
    dprintf(client->fd,
        "214 The following commands are recognized: \n\
        /help\n\
        /login ['user_name']\n\
        /logout\n\
        /users\n\
        /user['user_uuid']\n\
        /send ['user_uuid'] ['message_body']\n\
        /messages ['user_uuid']\n\
        /subscribe ['user_uuid']\n\
        /subscribed\n\
        /unsubscribe ['user_uuid']\n\
        /use ['team_uuid']\n\
        /create ['team_name'] ['team_description']\n\
        /list\n\
        /info\n");
}
