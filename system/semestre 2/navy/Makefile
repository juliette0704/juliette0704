##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make
##

SRC	=	src/navy.c    \
		src/create_square.c    \
		src/replace.c    \
		src/touch_boat.c    \
		src/test.c    \
		src/test2.c    \
		src/test3.c    \

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I ./include/

NAME	=	navy

all: makelib $(NAME)

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ) -L ./lib -lmy

makelib:
	make -C lib/my all

clean:
	make -C lib/my clean
	rm -f $(OBJ)

fclean:
	make -C lib/my fclean
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) makelib clean fclean
