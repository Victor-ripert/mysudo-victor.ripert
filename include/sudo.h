/*
** EPITECH PROJECT, 2025
** sudo.h
** File description:
** header file for sudo
*/

#ifndef SUDO_H
#define SUDO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

inspect_sudoers(const char *path, char *av);
get_current_user();
my_exec(char *arg0, char *arg1);
sudousers_passwd(const char *password_hash);

#endif /* !SUDO_H */
