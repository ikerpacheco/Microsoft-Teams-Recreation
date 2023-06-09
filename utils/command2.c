/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "prototypes.h"

char *clean_str(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n' || str[i] == '\r' || str[i] == '\t')
            str[i] = '\0';
    return str;
}
