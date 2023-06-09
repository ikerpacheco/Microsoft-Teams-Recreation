/*
** EPITECH PROJECT, 2023
** commands
** File description:
** commands
*/

#include "commands.h"

const commands_t commands[] = {
    {"/help", &command_help},
    {"/login", &command_login},
    {"/logout", &command_logout},
    {"/users", &command_users},
    {"/user", &command_user},
    {"/create", &command_create},
    {"/send", &command_send},
    {"/help", &command_help},
    {"/use", &command_use},
    {"/list", &command_list},
    {NULL, NULL}};
