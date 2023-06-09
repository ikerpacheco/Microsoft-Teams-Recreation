/*
** EPITECH PROJECT, 2023
** arr_len
** File description:
** arr_len
*/

#include "prototypes.h"

int arr_len(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return (i);
}
