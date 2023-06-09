/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** thread
*/

#include "../include/structs.h"
#include "../include/prototypes.h"

t_thread *init_thread_struct(char *title, char *body, char *user_uuid,
char *uuid)
{
    t_thread *thread_struct = malloc(sizeof(t_thread));
    uuid_t tmp_uuid;

    if (uuid == NULL) {
        uuid_generate(tmp_uuid);
        thread_struct->uuid = malloc((sizeof(uuid_t) * 2) + 5);
        uuid_unparse(tmp_uuid, thread_struct->uuid);
    } else {
        thread_struct->uuid = strdup(uuid);
    }
    time(&thread_struct->creation_time);
    thread_struct->title = (strlen(title) < MAX_NAME_LENGTH) ?
    strdup(title) : "";
    thread_struct->message = (strlen(body) < MAX_BODY_LENGTH) ?
    strdup(body) : "";
    thread_struct->user_uuid = strdup(user_uuid);
    thread_struct->comments = NULL;
    thread_struct->next = NULL;
    thread_struct->use_comment = NULL;
    return (thread_struct);
}

void free_thread(t_thread *thread)
{
    if (thread->title != NULL)
        free(thread->title);
    if (thread->message != NULL)
        free(thread->message);
    if (thread->user_uuid != NULL)
        free(thread->user_uuid);
    free(thread);
}

t_thread *get_thread(t_thread *thread, char *uuid)
{
    t_thread *temp = thread;

    while (temp != NULL) {
        if (temp->uuid == uuid) {
            return (temp);
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("error thread not found");
    }
    return (NULL);
}

void add_thread(t_server *server, t_thread *new_thread)
{
    t_thread *temp = server->use_team->use_channel->threads;

    if (!temp) {
        server->use_team->use_channel->threads = new_thread;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_thread;
}

void add_comment_to_thread(t_comment *comment, t_comment *new_comment)
{
    t_comment *temp_comment = comment;

    while (temp_comment != NULL) {
        temp_comment = temp_comment->next;
    }
    temp_comment = new_comment;
}
