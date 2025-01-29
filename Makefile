##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## to compile apparently
##

SRC =   src/inspect_sudoers.c \
        src/get_current_user.c \
        src/sudoers_passwd.c \
		src/my_exec.c

OBJ =  $(SRC:.c=.o)

NAME = libhashtable.a
EXEC = hashtable

CC = gcc

CFLAGS = -Wall -Wextra

CPPFLAGS = -I../include -Iinclude

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

test : $(OBJ)
		$(CC) $(OBJ) -o $(EXEC)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all clean fclean re
