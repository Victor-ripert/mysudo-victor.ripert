/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "sudo.h"
#include <stddef.h>
#include <stdlib.h>

void is_in_flag(char c, args_t **args_tab)
{
    for (int i = 0; (*args_tab)[i].flag != '0'; i++) {
        if ((*args_tab)[i].flag == c) {
            (*args_tab)[i].present = 1;
        }
    }
}

void arg_flag(char *args, args_t **args_tab)
{
    for (int i = 0; args[i] != '\0'; i++) {
        is_in_flag(args[i], args_tab);
    }
}

args_t *args_parsing(char **argv)
{
    // args_t args_tab[] = {
    //     {'u', 0},
    //     {'g', 0},
    //     {'E', 0},
    //     {'s', 0},
    //     {'0', 0}
    // };

    args_t *args_tab = malloc(sizeof(args_t) * 5);

    args_tab[0].flag = 'u';
    args_tab[0].present = 0;
    args_tab[0].flag = 'g';
    args_tab[0].present = 0;
    args_tab[0].flag = 'E';
    args_tab[0].present = 0;
    args_tab[0].flag = 's';
    args_tab[0].present = 0;
    args_tab[0].flag = '0';
    args_tab[0].present = 0;
    for (int i = 0; argv[i] != NULL; i++) {
        if (argv[i][0] == '-') {
            arg_flag(argv[i], &args_tab);
        }
    }
    return args_tab;
}