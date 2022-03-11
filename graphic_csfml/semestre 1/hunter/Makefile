##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task
##

NAME	=	my_hunter

SRC    =	my_hunter.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -l csfml-graphics -lcsfml-system -lcsfml-window -lm

all:	$(NAME)


$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re: fclean all