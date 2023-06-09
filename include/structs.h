/*
** EPITECH PROJECT, 2023
** structs
** File description:
** structs
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <fcntl.h>
#include <uuid/uuid.h>
#include <sys/queue.h>

#pragma once

#define MAX_NAME_LENGTH        32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH        512
#define MAX_CLIENTS            1000

enum useEnum {
    USER,
    TEAM,
    CHANNEL,
    THREAD,
    REPLY
};

typedef struct s_client {
    char *uuid;
    bool is_logged;
    char *username;
    int fd;
    int is_passive; // cambiar a bool
    int port;
    int data_fd;

    struct chats *chats;
    struct s_client *next;
} t_client;

typedef struct message {
    char *uuid;
    char *body;
    char *user_uuid;
    time_t creation_time;
    struct message *next;
} t_message;

typedef struct chats {
    char *uuid;
    char *user_uuid;
    struct message *messages;
    struct chats *next;
} t_chats;

typedef struct s_comment {
    char *uuid;
    char *message;
    char *user_uuid;
    time_t creation_time;
    struct s_comment *next;
} t_comment;

typedef struct s_thread {
    char *uuid;
    char *title;
    char *message;
    char *user_uuid;
    time_t creation_time;
    struct s_comment *comments;
    struct s_comment *use_comment;
    struct s_thread *next;
} t_thread;

typedef struct s_channel {
    char *uuid;
    char *name;
    char *description;
    time_t creation_time;
    struct s_thread *threads;
    struct s_thread *use_thread;
    struct s_channel *next;
} t_channel;

typedef struct s_team {
    char *uuid;
    char *name;
    char *description;
    struct s_channel *channels;
    struct s_channel *use_channel;
    struct s_team *next;
} t_team;

typedef struct s_server {
    char *path;
    int server_fd;
    int client_fd;
    int data_fd;
    t_client *clients;
    struct sockaddr_in client_addr;
    struct sockaddr_in data_addr;
    struct sockaddr_in server_addr;
    fd_set sockets_set;
    int max_socket;
    char **command_arr;
    t_team *teams;
    int use;
    t_team *use_team;
} t_server;
