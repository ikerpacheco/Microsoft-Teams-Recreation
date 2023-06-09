/*
** EPITECH PROJECT, 2023
** prototypes.h
** File description:
** prototypes.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <signal.h>
#include <errno.h>
#include "structs.h"
#include "../libs/myteams/logging_server.h"
#include "../libs/myteams/logging_client.h"

#pragma once

// Main functions prototypes
int main(int ac, char **av);
void my_teams(t_server *server);

// Error handling functions prototypes
void error_handling(int ac, char **av);
char *open_path(char **av);

// Socket functions prototypes
void send_to_clients(t_server *server);
int accept_socket(int fd, struct sockaddr_in client, socklen_t client_len);
void listen_socket(int fd);
char *read_command(int fd, char *command);
void bind_socket(int fd, struct sockaddr_in name);
int create_socket(int domain, int type, int protocol, char *name);
struct sockaddr_in initialize_struct_data(int port, struct sockaddr_in name);

// Utils functions prototypes
char *clean_str(char *str);
char **get_client_command(char *raw);

char **my_str_to_arr(char *str, char sep);
int arr_len(char **arr);
int check_logged(t_server *server, t_client *client);

// Initialize structs
t_server *init_server_struct(int ac, char **av);

// Handle commands
void handle_command(t_server *server, t_client *client);

// Handle connections
void manage_connections(t_server *server);
void select_socket(int fd, fd_set *set, int max_socket);
void accept_new_connection(t_server *server);
void add_clients_to_set(t_server *server);
void read_clients_commands(t_server *server);

// Client linked list functions
t_client *init_client_struct(int fd, char *username, char *uuid);
void add_client(t_server *server, t_client *new_client);
void free_client(t_client *client);
t_client *get_client(t_client *client, char *uuid);
void free_all_clients(t_client *client, char *del_uuid);

// Commands linked list functions
t_comment *init_comment_struct(char *comment, char *user_uuid, char *uuid);
void free_comment(t_comment *comment);
t_comment *get_comment(t_comment *comment, char *uuid);
void add_comment(t_comment *comment, t_comment *new_comment);
void remove_comment(t_comment *comment, char *uuid);

// Threads linked list functions
t_thread *init_thread_struct(char *title, char *body,
char *user_uuid, char *uuid);
void free_thread(t_thread *thread);
t_thread *get_thread(t_thread *thread, char *uuid);
void add_thread(t_server *server, t_thread *new_thread);
void add_comment_to_thread(t_comment *comment, t_comment *new_comment);

// Channels linked list functions
t_channel *init_channel_struct(char *name, char *description,
char *user_uuid, char *uuid);
void free_channel(t_channel *channel);
t_channel *get_channel(t_channel *channel, char *uuid);
void add_channel(t_server *server, t_channel *new_channel);

// Teams linked list functions
t_team *init_team_struct(char *name, char *description,
char *user_uuid, char *uuid);
void free_team(t_team *team);
t_team *get_team(t_team *team, char *uuid);
void add_team(t_server *server, t_team *new_team);
void delete_client(t_client *client, char *del_uuid);

// Chats linked list functions
t_chats *init_chats_struct(char *uuid, char *user_uuid);
t_chats *get_chat(t_client *client, char *uuid);
void add_chat(t_client *client, t_chats *new_chat);

// Messages linked list functions
t_message *init_message_struct(char *body, char *user_uuid, char *uuid);
void add_message(t_chats *chats, t_message *new_message);
t_message *get_message(t_chats *messages, char *uuid);

void check_response(t_client *client);
void handle_signal_action(int sig_number);

// Create command functions prototypes
void create_thread(t_server *server, t_client *client);
void create_channel(t_server *server, t_client *client);
void create_team(t_server *server, t_client *client);
void create_comment(t_server *server, t_client *client);

//Use command function prototypes
void use_channel(t_server *server, t_client *client);
void use_team(t_server *server, t_client *client);
void use_thread(t_server *server, t_client *client);
