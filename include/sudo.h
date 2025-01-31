/*
** EPITECH PROJECT, 2025
** sudo.h
** File description:
** header file for sudo
*/

#ifndef SUDO_H
    #define SUDO_H

typedef struct args_s {
    char flag;
    int present;
} args_t;

void inspect_sudoers(const char *path, char *av);
int get_current_user();
void my_exec(char *arg0, char *arg1);
int sudousers_passwd(const char *password_hash);
void exec_function(char **argv, char **envp, int flag_e);
args_t *args_parsing(char **argv);

#endif /* SUDO_H */
