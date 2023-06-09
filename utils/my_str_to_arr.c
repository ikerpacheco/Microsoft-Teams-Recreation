/*
** EPITECH PROJECT, 2023
** my_str_to_arr.c
** File description:
** my_str_to_arr
*/

#include "prototypes.h"

int count_chars(char *str, char letter)
{
    int count = 0;

    while (*str) {
        if (*str == letter)
            count++;
        str++;
    }
    return count;
}

char **my_arrmalloc(int size, int words)
{
    char **arr = malloc(sizeof(char *) * (words + 1));

    for (int i = 0; i < words; i++)
        arr[i] = malloc(sizeof(char) * (size + 1));
    arr[words] = NULL;
    return arr;
}

char **my_str_to_arr(char *str, char sep)
{
    int words = count_chars(str, sep) + 1;
    char **word_array = my_arrmalloc(0, words);

    for (int i = 0; i < words; i++) {
        word_array[i] = str;
        while (*str != '\0' && *str != sep)
            str++;
        *(str++) = '\0';
    }
    return word_array;
}
