##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make
##

SRC	=	src/main.c    \
		src/str_to_word_array.c    \
		src/create.c	\
		src/grid.c	\
		src/game.c	\
		src/cant_move.c	\
		src/pause.c	\
		src/debug_mode.c    \
		src/alpha_order.c    \
		src/toolss.c    \
		src/tools_file.c    \
		src/create_map.c    \
		src/clementinooo.c    \

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I ./include/

NAME	=	tetris

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
