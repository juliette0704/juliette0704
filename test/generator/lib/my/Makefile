##
## EPITECH PROJECT, 2021
## makefile
## File description:
## task01
##

NAME	=	libmy.a

SRC	=	my_getnbr.c	\
        my_putchar.c	\
        my_put_nbr.c	\
		my_putstr.c	\
        my_strlen.c	\
        my_int_to_str.c	\
		char_to_int.c    \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):        $(OBJ)
		ar rc $(NAME) $(OBJ)

		cp my.h ../../include

		cp libmy.a ../

clean :
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		rm -f ../$(NAME)
		rm -f ../../include/my.h
