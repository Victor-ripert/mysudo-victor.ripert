/*
** EPITECH PROJECT, 2025
** Sudo
** File description:
** inspect sudoers
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include "sudo.h"


int grp_usr_loop(char *line, char *username)
{
    char *line_tok = strdup(line);
    char *usrname_tok;
    int count = 0;

    usrname_tok = strdup(strtok(line_tok, ":,"));
    while (usrname_tok != NULL) {
        count++;
        if (usrname_tok[strlen(usrname_tok) - 1] == '\n') {
            usrname_tok[strlen(usrname_tok) - 1] = '\0';
        }
        if (strcmp(username, usrname_tok) == 0) {
            return 1;
        }
        usrname_tok = strtok(NULL, ":,");
    }
    return 0;
}

int is_usr_in(char *line, char *grp_name, char *username)
{
    char *line_tok = strdup(line);
    char *group;

    group = strtok(line_tok, ":");
    if (strcmp(grp_name, group) != 0) {
        return 0;
    }
    if (grp_usr_loop(line, username) == 1) {
        return 1;
    }
    return 0;
}

int pars_group(char *grp_name, char *username)
{
    FILE *stream;
    char *line;
    int getline_return_value = 0;
    size_t n = 0;

    stream = fopen("/etc/group", "r");
    if (stream == NULL) {
        printf("RATER\n");
    }
    while (getline_return_value != -1) {
        getline_return_value = getline(&line, &n, stream);
        if (is_usr_in(line, grp_name, username) != 0) {
            return 1;
        }
    }
    return 0;
}

int is_usr_in_group(grp_list_t *list)
{
    grp_list_t *tmp;
    char *username = get_username();

    tmp = list;
    while (tmp != NULL) {
        if (tmp->gid[0] != ' ' && pars_group(tmp->gid, username) == 1) {
            return 1;
        }
        tmp = tmp->next;
    }
    printf("%s is not in the sudoers file.\n", username);
    printf("This incident has been reported to the administrator.\n");
    return 0;
}
