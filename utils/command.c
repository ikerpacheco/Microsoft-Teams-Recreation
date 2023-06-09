/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "prototypes.h"

char *get_command(char *str)
{
    char *param = malloc(sizeof(char) * 1024);
    int i = 0;

    memset(param, '\0', 1024);
    for (; str[i] != ' ' && str[i] != '\0'; i++)
        param[i] = str[i];
    return param;
}

char *cutstr(char *str, int start)
{
    char *new = NULL;
    int i = 0;

    if (str == NULL || strlen(str) <= 0)
        return NULL;
    new = malloc((sizeof(char) * strlen(str)) + 1);
    memset(new, '\0', strlen(str) + 1);
    if (start >= strlen(str))
        return NULL;
    for (; str[start] != '\0'; start++, i++)
        new[i] = str[start];
    return new;
}

char *get_param(char *str)
{
    char *param = malloc(sizeof(char) * 1024);
    int i = 0;

    memset(param, '\0', 1024);
    for (; str[i] != '"'; i++)
        if (str[i] == '\0')
            return NULL;
    i++;
    for (int n = 0; str[i] != '"' && str[i] != '\0'; i++, n++) {
        param[n] = str[i];
    }
    return param;
}

char *clean_duplicate_spaces(char *str)
{
    char *new = malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    int n = 0;

    memset(new, '\0', strlen(str) + 1);
    for (; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] == ' ')
            continue;
        new[n] = str[i];
        n++;
    }
    return new;
}

char **get_client_command(char *raw)
{
    char **command = malloc(sizeof(char *) * 4);
    char *tmp = NULL;
    int param = 0;

    command[0] = get_command(raw);
    tmp = cutstr(raw, strlen(command[0]) + 1);
    command[1] = tmp ? get_param(tmp) : NULL;
    tmp = cutstr(tmp, tmp ? (strlen(command[1]) + 2) : 0);
    command[2] = tmp ? get_param(tmp) : NULL;
    command[3] = NULL;
    return command;
}