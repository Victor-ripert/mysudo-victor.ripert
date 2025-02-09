##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## make units tests
##

SRC = src/main.c	\
	src/exec_function.c	\
	src/inspect_sudoers.c	\
	src/is_usr_in_group.c	\
	src/get_username.c	\
	src/push_to_list.c	\
	src/my_strdup_minus.c	\
	display_list.c	\
	src/word_array/my_str_to_word_array.c	\
	src/word_array/my_strlen.c	\
	src/word_array/my_word_len.c	\
	src/verif_password.c

NAME	=	my_sudo

OBJ	=	$(SRC:.c=.o)

DEBUG_VALGRIND += -g3 -ggdb3 -iquote ./include

CPPFLAGS += -g3 -ggdb3 -iquote ./include -Wall -Wextra -lc

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lcrypt

debug: fclean $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm $(DEBUG_VALGRIND)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean  all

coding_style: fclean
	clear && ../../coding-style.sh .
	cat coding-style-reports.log
	@rm -f coding-style-reports.log
