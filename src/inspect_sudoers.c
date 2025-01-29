/*
** EPITECH PROJECT, 2025
** inspect_sudoers.c
** File description:
** checks which sudoers is asked
*/
#include "sudo.h"

void inspect_sudoers(const char *path, char *av)
{
    FILE *file;

    file = fopen("/etc/sudoers", "r");
    if (file == 0)
    printf("ERROR no file to open.\n");
    return 0;

}