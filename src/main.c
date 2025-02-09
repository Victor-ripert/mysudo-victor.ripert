/*
** EPITECH PROJECT, 2025
** my_exec.c
** File description:
** dunno
*/
// #define _XOPEN_SOURCE
// #define _XOPEN_CRYPT
// #define _XOPEN_SOURCE 600
// #define _GNU_SOURCE
// #define _XOPEN_CRYPT 600
// #include <unistd.h>
#include <crypt.h>
#include <stdlib.h>
#include "sudo.h"
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
    if (argc < 2) {
        return 84;
    }
    if (strcmp(argv[1], "-h") == 0) {
        printf("usage: ./my_sudo -h\n");
        printf("usage: ./my_sudo [-ugEs] [command [args ...]]\n");
        return 0;
    }
    if (verif_password() != 1) {
        return 84;
    }
    if (inspect_sudoers() != 1) {
        return 84;
    }
    exec_function(argv, envp, 0);
    return 0;
}
