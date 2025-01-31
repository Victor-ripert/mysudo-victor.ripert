/*
** EPITECH PROJECT, 2025
** my_exec.c
** File description:
** dunno
*/

#include "sudo.h"

int main(int argc, char **argv, char **envp)
{
    // printf("avcant agrs_parsing\n");
    // args_t *args_tab = args_parsing(argv);
    // printf("après args_parsing\n");

    // printf("%d\n", args_tab[2].present);

    if (argc < 3) {
        return 84;
    }
    exec_function(argv, envp, envp);
    return 0;
}