##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task
##

NAME	=	my

SRC    =	myls_ngCopy3.c    \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)