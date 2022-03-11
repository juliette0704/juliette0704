##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make
##

SRC	=	src/main.c    \
		src/tools/tools_for_map.c    \
		src/map.c    \

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I ./include/

NAME	=	my_sokoban

all: makelib $(NAME)

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ) -L ./lib -lmy -g3 -lncurses

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
