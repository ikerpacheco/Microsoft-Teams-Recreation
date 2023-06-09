/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "prototypes.h"

char *open_path(char **av)
{
    char *path = strdup(av[2]);
    if (chdir(path) == -1) {
        printf("Invalid path\n");
        exit (84);
    }
    return (path);
}

void check_arguments(int ac, char **av)
{
    if (ac > 3) {
        printf("Invalid number of arguments\n");
        exit (84);
    }
    if (av[1] == NULL || av[2] == NULL) {
        printf("Invalid number of arguments\n");
        exit (84);
    }
}

void error_handling(int ac, char **av)
{
    check_arguments(ac, av);
    if (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0) {
        printf("USAGE: ./myftp port path\n");
        printf("      port  is the port number on "
            "which the server utils listens\n");
        printf("      path  is the path to the home "
            "directory for the Anonymous user\n");
        exit (84);
    }
    if (av[1][0] == '-') {
        printf("Unknown option, try -h or -help\n");
        exit (84);
    }
    if (atoi(av[2]) < 1024 || atoi(av[2]) > 65535) {
        printf("Invalid port number\n");
        exit (84);
    }
}
