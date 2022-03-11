##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task
##

##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## task
##

NAME	=	my_runner

SRC    =	my_runner.c	   \
			ground.c    \
			running.c    \
			score.c    \
			my_putstr.c    \
			window.c    \
			sprite_bool.c    \

OBJ	=	$(SRC:.c=.o)

CFLAGS = -g3 -l csfml-graphics -lcsfml-system -lcsfml-window -lm -lcsfml-audio

all:	$(NAME)


$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f ../../include/my.h

re: fclean all