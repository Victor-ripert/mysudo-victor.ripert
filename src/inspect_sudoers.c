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

void add_in_list(grp_list_t **list, char *line)
{
    char *line_tok = strdup(line);
    char *sudoersname;

    sudoersname = strtok(line_tok, "\t ");
    if (sudoersname[0] == '%') {
        sudoersname = my_strdup_minus(sudoersname);
    }
    push_to_list(list, sudoersname);
}

grp_list_t *pars_sudoers(void)
{
    FILE *stream;
    char *line;
    char *line_tok;
    grp_list_t *list = NULL;
    int getline_return_value = 0;
    size_t n = 0;
    char *sudoersname;

    stream = fopen("/etc/sudoers", "r");
    if (stream == NULL) {
        printf("RATER\n");
        return NULL;
    }
    while (getline_return_value != -1) {
        getline_return_value = getline(&line, &n, stream);
        if (line[0] != '#' && getline_return_value > 1) {
            add_in_list(&list, line);
        }
    }
    return list;
}

int inspect_sudoers(void)
{
    grp_list_t *suoders = pars_sudoers();

    if (is_usr_in_group(suoders) == 1) {
        return 1;
    }
    return 0;
}
