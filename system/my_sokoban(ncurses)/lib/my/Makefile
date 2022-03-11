##
## EPITECH PROJECT, 2021
## makefile
## File description:
## libmy
##

SRC	=	char_to_int.c	\
		my_putstr.c	\
		my_put_nbr.c	\
		my_strstr.c    \
		my_strlen.c    \
		str_to_word_array.c    \

NAME	=	libmy.a

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I ./../../include/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean
