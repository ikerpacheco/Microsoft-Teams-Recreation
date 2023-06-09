/*
** EPITECH PROJECT, 2023
** Init data
** File description:
** Init data
*/

#include "prototypes.h"

struct sockaddr_in initialize_struct_data(int port, struct sockaddr_in name)
{
    memset(&name, 0, sizeof(name));
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = INADDR_ANY;

    return name;
}
