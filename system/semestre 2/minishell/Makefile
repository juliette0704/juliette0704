##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make
##

SRC	=	src/main.c    \
		src/str_to_word_array.c    \
		src/cd.c    \
		src/str_to_word_array2.c    \
		src/str_to_word_array3.c    \
		src/run_command.c    \
		src/tools/tools1.c    \
		src/str_to_word_array4.c    \
		src/setenv.c    \
		src/unsetenv.c    \
		src/no_space.c    \

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I ./include/

NAME	=	mysh

all: makelib $(NAME)

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ) -L ./lib -lmy -g3

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
