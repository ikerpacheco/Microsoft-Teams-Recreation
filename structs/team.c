/*
** EPITECH PROJECT, 2023
** my_teams
** File description:
** team
*/

#include "../include/structs.h"
#include "../include/prototypes.h"

t_team *init_team_struct(char *name, char *description, char *user_uuid,
char *uuid)
{
    t_team *team_struct = malloc(sizeof(t_team));
    uuid_t tmp_uuid;

    if (uuid == NULL) {
        uuid_generate(tmp_uuid);
        team_struct->uuid = malloc((sizeof(uuid_t) * 2) + 5);
        uuid_unparse(tmp_uuid, team_struct->uuid);
    } else {
        team_struct->uuid = strdup(uuid);
    }
    team_struct->name = (strlen(name) < MAX_NAME_LENGTH) ? strdup(name) : "";
    team_struct->description = (strlen(description) < MAX_DESCRIPTION_LENGTH)
    ? strdup(description) : "";
    team_struct->channels = NULL;
    team_struct->next = NULL;
    team_struct->use_channel = NULL;

    return (team_struct);
}

void free_team(t_team *team)
{
    if (team->name != NULL)
        free(team->name);
    if (team->description != NULL)
        free(team->description);
    free(team);
}

void add_team(t_server *server, t_team *new_team)
{
    t_team *temp = server->teams;

    if (!temp) {
        server->teams = new_team;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_team;
}

void delete_team(t_team *team, char *del_uuid)
{
    t_team *temp = team;
    t_team *del;

    while (temp != NULL) {
        if (temp->uuid == del_uuid) {
            del = temp;
            temp = temp->next;
            free_team(del);
        }
        temp = temp->next;
    }
}

t_team *get_team(t_team *team, char *uuid)
{
    t_team *temp = team;

    while (temp != NULL) {
        if (temp->uuid == uuid) {
            return (temp);
        }
        temp = temp;
    }
}
