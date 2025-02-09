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

typedef struct grp_list_s {
    char *gid;
    char *grp_name;
    struct grp_list_s *next;
} grp_list_t;

void push_to_list(grp_list_t **begin, char *gid);
char *my_strdup_minus(char *str);
void display_list(grp_list_t *list);

int inspect_sudoers(void);
int get_current_user(void);
void my_exec(char *arg0, char *arg1);
int sudousers_passwd(const char *password_hash);
void exec_function(char **argv, char **envp, int flag_e);
args_t *args_parsing(char **argv);
char *get_username(void);
int is_usr_in_group(grp_list_t *list);
int verif_password(void);

char **my_str_to_word_array(char *str, char separator);
int my_strlen(char const *str);
int my_word_len(char *str, char separator, int i);

#endif /* SUDO_H */
