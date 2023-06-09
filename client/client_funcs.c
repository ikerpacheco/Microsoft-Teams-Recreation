/*
** EPITECH PROJECT, 2023
** B-NWP-400-BAR-4-1-myteams-iker.pacheco-figueiredo
** File description:
** client_funcs
*/

#include "prototypes.h"
#include "protocol.h"
#include "../libs/myteams/logging_client.h"
#include "../libs/myteams/logging_server.h"

void check_command_client(char **arr)
{
    int n = 0;

    for (n = 0; protocol[n].code != NULL; n++) {
        if (strcmp(arr[0], protocol[n].code) == 0) {
            protocol[n].func(arr);
        }
    }
}

void check_response(t_client *client)
{
    char *buffer = malloc(sizeof(char) * 10024);
    char **lines;
    char **arr;
    int n = 0;

    memset(buffer, 0, 10024);
    if (read(client->fd, buffer, 10024) != 0) {
        lines = my_str_to_arr(buffer, '\n');
        for (n = 0; lines[n] != NULL; n++) {
            arr = my_str_to_arr(lines[n], ',');
            check_command_client(arr);
        }
    }
}

void handle_signal_action(int sig_number)
{
    exit(0);
}
