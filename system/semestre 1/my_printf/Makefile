##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task
##

NAME	=	libmy

SRC    =	my_getnbr.c     \
			my_printf.c    \
			my_isneg.c    \
			my_putchar.c    \
			my_putstr.c    \
			my_revstr.c    \
			my_swap.c    \
			my_put_nbr.c	\
			my_put_unsigned.c	\
			powerlong.c    \
			count_digitslong.c    \
			my_putchar2.c    \
			convert_dec_hexa2.c    \
			convert_dec_hexa_maj2.c    \
			my_putstr2.c    \
			my_put_nbr2.c    \
			convert_dec_octal.c    \
			my_strlen.c    \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a *.o

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h