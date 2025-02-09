/*
** EPITECH PROJECT, 2025
** my_strdup_minus
** File description:
** strdup -1 char a the end
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup_minus(char *str)
{
    int str_len = strlen(str);
    char *result = malloc(sizeof(char) * (str_len));

    for (int i = 1; i < str_len; i++) {
        result[i - 1] = str[i];
    }
    result[str_len] = '\0';
    return result;
}
