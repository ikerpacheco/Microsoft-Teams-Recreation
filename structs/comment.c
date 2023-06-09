/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** comment
*/

#include "../include/structs.h"
#include "../include/prototypes.h"

t_comment *init_comment_struct(char *comment, char *user_uuid, char *uuid)
{
    t_comment *comment_struct = malloc(sizeof(t_comment));
    uuid_t tmp_uuid;

    if (comment_struct == NULL) {
        uuid_generate(tmp_uuid);
        comment_struct->uuid = malloc((sizeof(uuid_t) * 2) + 5);
        uuid_unparse(tmp_uuid, comment_struct->uuid);
    } else {
        comment_struct->uuid = strdup(uuid);
    }
    time(&comment_struct->creation_time);
    comment_struct->message = (strlen(comment) < MAX_BODY_LENGTH) ?
    strdup(comment) : "";
    uuid_unparse(uuid, comment_struct->uuid);
    comment_struct->user_uuid = strdup(user_uuid);
    comment_struct->next = NULL;
    return (comment_struct);
}

void free_comment(t_comment *comment)
{
    if (comment->message != NULL)
        free(comment->message);
    if (comment->user_uuid != NULL)
        free(comment->user_uuid);
    free(comment);
}

t_comment *get_comment(t_comment *comment, char *uuid)
{
    t_comment *temp = comment;

    while (temp != NULL) {
        if (temp->uuid == uuid) {
            return (temp);
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("error comment not found");
    }
    return (NULL);
}

void add_comment(t_comment *comment, t_comment *new_comment)
{
    t_comment *temp = comment;

    while (temp != NULL) {
        temp = temp->next;
    }
    temp = new_comment;
}

void remove_comment(t_comment *comment, char *uuid)
{
    t_comment *temp = comment;
    t_comment *del;

    while (temp != NULL) {
        if (temp->uuid == uuid) {
            del = temp->next;
            temp->next = temp->next->next;
            free_comment(del);
            return;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("error comment not found");
    }
}
