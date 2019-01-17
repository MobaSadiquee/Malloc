##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make malloc
##

NAME	= libmy_malloc.so

SRC   	= ./src/malloc.c \
	  ./src/calloc.c \
	  ./src/realloc.c \
	  ./src/show_alloc_mem.c \
	  ./src/free.c

CC	= gcc

RM	= rm -rf

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -I./include -I. -W -Wall -Wextra -fPIC -pthread

LDFLAGS	= -shared -o $(NAME)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(LDFLAGS) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all
