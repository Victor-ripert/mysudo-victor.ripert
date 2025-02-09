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
#include <stdlib.h>
#include "sudo.h"

int find_name_in_line(char *line, uid_t uid, char **username)
{
    char *line_tok = strdup(line);
    char *name;
    char *tmp = " ";
    int i = 0;
    char **pwd_array[3];

    for (tmp = strtok(line_tok, ":"); i < 3; tmp = strtok(NULL, ":")) {
        pwd_array[i] = strdup(tmp);
        i++;
    }
    if (atoi(pwd_array[2]) == uid) {
        (*username) = pwd_array[0];
        return 1;
    } else {
        return 0;
    }
}

char *pars_passwd(uid_t uid)
{
    FILE *stream;
    char *line;
    char *line_tok;
    int getline_return_value = 0;
    size_t n = 0;
    char *username;
    char **pwd_array[3];

    stream = fopen("/etc/passwd", "r");
    if (stream == NULL) {
        printf("RATER\n");
    }
    while (getline_return_value != -1) {
        getline_return_value = getline(&line, &n, stream);
        if (find_name_in_line(line, uid, &username) == 1) {
            return username;
        }
    }
    return NULL;
}

char *get_username(void)
{
    uid_t uid = getuid();
    char *username = strdup(pars_passwd(uid));

    return username;
}
