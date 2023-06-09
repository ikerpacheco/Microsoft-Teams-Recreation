/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "prototypes.h"

int main(int ac, char **av)
{
    t_server *server = init_server_struct(ac, av);

    my_teams(server);
}
