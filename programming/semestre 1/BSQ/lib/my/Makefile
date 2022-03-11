##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task
##

SRC    =	my_getnbr.c     \
		my_isneg.c    \
		my_putchar.c    \
		my_putstr.c    \
		my_revstr.c    \
		my_swap.c    \
		my_put_nbr.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)

	ar rc $(NAME) $(OBJ)

	cp my.h ../../include

	cp libmy.a ../

clean:  
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h
