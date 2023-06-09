/*
** EPITECH PROJECT, 2023
** c_event_logged_in
** File description:
** c_event_logged_in
*/

#include "protocol.h"

int c_event_thread_reply_received(char **args)
{
    int response = client_event_thread_reply_received(args[1], args[2],
                                                    args[3], args[4]);
    return (0);
}
