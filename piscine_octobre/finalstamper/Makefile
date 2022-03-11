##
## EPITECH PROJECT, 2021
## MAKEFILE
## File description:
## Makefile for finalstumper
##

SRC	=	rush3.c

NAME	=	rush3

all:	$(NAME)

$(NAME):	$(SRC)
		cd lib/my && make
		gcc -o $(NAME) $(SRC) -I include/ -L lib/my -lmy

clean:	$(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
