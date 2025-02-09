/*
** EPITECH PROJECT, 2025
** my_exec.c
** File description:
** dunno
*/
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include "sudo.h"

char *get_hash(char *username)
{
    FILE *stream;
    char *line;
    char *line_tok;
    int getline_return_value = 0;
    size_t n = 0;

    stream = fopen("/etc/shadow", "r");
    if (stream == NULL) {
        printf("fopen error");
        return NULL;
    }
    while (getline_return_value != -1) {
        getline_return_value = getline(&line, &n, stream);
        line_tok = strtok(line, ":");
        if (strcmp(line_tok, username) == 0) {
            return strtok(NULL, ":");
        }
    }
    return NULL;
}

int is_password_good(char *hash, char *username)
{
    char *password = malloc(sizeof(char) * 100);
    char **hash_pattern = my_str_to_word_array(hash, '$');
    char *hash_result;

    printf("[sudo] password for %s: ", username);
    scanf("%s", password);
    if (password == NULL) {
        return 0;
    }
    hash_result = crypt(password, hash);
    if (strcmp(hash, hash_result) == 0) {
        return 1;
    }
    if (strcmp(hash_result, "*0") == 0) {
        printf("error password\n");
        return 0;
    }
    return 0;
}

int verif_password(void)
{
    char *username = get_username();
    char *hash = get_hash(username);

    for (int i = 0; i < 2; i++) {
        if (is_password_good(hash, username) == 1) {
            return 1;
        }
        printf("Sorry, try again.\n");
    }
    if (is_password_good(hash, username) == 1) {
        return 1;
    }
    printf("sudo: 3 incorrect password attempts\n");
    return 0;
}
