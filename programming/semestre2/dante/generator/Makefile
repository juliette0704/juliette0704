##
## EPITECH PROJECT, 2021
## makefile
## File description:
## task01
##

SRC	=	src/main.c	   \
		src/edit_stack.c    \
		src/check_neigbourh.c    \
		src/tools_for_maze.c    \
		src/imperfect.c    \
		src/check_maze.c    \

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -g3 -I ./include/

NAME	=	generator

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
