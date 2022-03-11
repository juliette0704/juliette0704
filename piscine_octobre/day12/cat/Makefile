##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task
##

NAME	=	cat

INC_LIB =	-I./include -L../lib -lmy

SRC    =	cat.c    \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)

	make -C ../lib/my/


	gcc $(OBJ) -o $(NAME) $(INC_LIB)

clean:  
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all