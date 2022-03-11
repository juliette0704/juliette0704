##
## EPITECH PROJECT, 2021
## makefile
## File description:
## make
##

SRC	=	src/main.c    \
		src/game_rules.c    \
		src/background.c	\
		src/init_game.c	\
		src/init_sprites.c	\
		src/init_towers.c	\
		src/launch_game.c	\
		src/menu.c	\
		src/mouse.c	\
		src/move_sprites.c	\
		src/pause.c	\
		src/print_sprites.c	\
		src/score.c	\
		src/site_towers.c	\
		src/waves.c	\
		src/sprite_bit.c    \

OBJ	=	$(SRC:.c=.o)

CFLAGS	= -I ./include/ -g3

NAME	=	my_defender

all: makelib $(NAME)

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ) -L ./lib -lmy -g3 -l csfml-graphics -lcsfml-system -lcsfml-window -lm -lcsfml-audio

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
