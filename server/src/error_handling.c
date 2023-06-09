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
    if (ac != 2) {
        printf("Invalid number of arguments\n");
        exit (84);
    }
    if (ac == 2 && (strcmp(av[1], "-help") == 0 || strcmp(av[1], "-h") == 0)) {
        printf("USAGE: ./myteams_server port\n\n\tport is the port ");
        printf("number on which the server socket listens.\n");
        exit (0);
    }
}

void error_handling(int ac, char **av)
{
    check_arguments(ac, av);
    if (av[1][0] == '-') {
        printf("Unknown option, try -h or -help\n");
        exit (84);
    }
    if (atoi(av[1]) < 1024 || atoi(av[1]) > 65535) {
        printf("Invalid port number\n");
        exit (84);
    }
}
