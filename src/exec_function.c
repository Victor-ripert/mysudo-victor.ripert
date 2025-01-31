/*
** EPITECH PROJECT, 2025
** my_exec.c
** File description:
** dunno
*/

#include "sudo.h"
#include <stddef.h>
#include <unistd.h>

void exec_function(char **argv, char **envp, int flag_e)
{
    if (flag_e == 1) {
        execvpe(argv[1], argv, envp);
        return;
    }
    execvpe(argv[1], argv, NULL);
}