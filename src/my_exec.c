/*
** EPITECH PROJECT, 2025
** my_exec.c
** File description:
** dunno
*/

#include "sudo.h"

void my_exec(char *arg0, char *arg1)
{
    arg0 = fopen("./print_cat.c", "r");
}

int main(int ac, char *av)
{
    if (ac < 3)
    return 84;
    my_exec(av[1], av[2]);
}