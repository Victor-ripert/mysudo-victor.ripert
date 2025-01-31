##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## make units tests
##

SRC = src/main.c	\
	src/exec_function.c	\
	src/args_parsing.c

NAME	=	my_sudo

OBJ	=	$(SRC:.c=.o)

DEBUG_VALGRIND += -g3 -iquote ./include

CPPFLAGS += -g3 -iquote ./include -Wall -Wextra

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

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
