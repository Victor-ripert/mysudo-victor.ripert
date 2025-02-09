/*
** EPITECH PROJECT, 2025
** my_word_len
** File description:
** get the len of a word
*/
#include <stdlib.h>
#include <stdio.h>

int my_word_len(char *str, char separator, int i)
{
    int count = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            return count;
        }
        count++;
    }
    return count;
}
