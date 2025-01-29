/*
** EPITECH PROJECT, 2025
** sudousers_passwd.c
** File description:
** checks the password of the sudo user identified before
*/

#include "sudo.h"


int sudousers_passwd(const char *password_hash)
{
    FILE* hash_key =  fopen("/etc/shadow", "r"); 
    
    strcmp(password_hash, hash_key);
    if (password_hash = hash_key)
    printf(hash_key);
    return 0;
}