/*
** EPITECH PROJECT, 2025
** sudo
** File description:
** push_to_list
*/

#include "sudo.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void push_to_list(grp_list_t **begin, char *gid)
{
    grp_list_t *node = malloc(sizeof(grp_list_t));

    node->gid = strdup(gid);
    node->next = NULL;
    if ((*begin) == NULL) {
        (*begin) = node;
        return;
    } else {
        node->next = (*begin);
        (*begin) = node;
    }
}
