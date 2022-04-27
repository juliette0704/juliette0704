##
## EPITECH PROJECT, 2021
## makefile
## File description:
## task01
##

CFLAGS	=	-g3 -I./include -lmy -L./lib -lcsfml-graphics
CFLAGS2 = 	-lcsfml-system -lcsfml-audio -lcsfml-window -lm

NAME	=	my_rpg

SRC	=	src/main.c	\
		src/initialization.c	\
		src/start_game.c	\
		src/draw.c	\
		src/tools.c	\
		src/animation_mouv.c	\
		src/talk.c	\
		src/deplace_hero.c	\
		src/draw_map.c	\
		src/menu.c    \
		src/rain.c    \
		src/speaker.c    \
		src/start_map.c	\
		src/draw_house.c	\
		src/draw_poster.c	\
		src/slime.c	\
		src/hitbox_attack_hero.c	\
		src/cursor.c	\
		src/save_to_struct.c    \
		src/life.c    \

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(SRC)
	make -C ./lib/my/
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(CFLAGS2)

clean:
		rm -f $(OBJ)
		make clean -C ./lib/my

fclean: clean
		rm -f $(NAME)
		rm -f vgcore*
		make fclean -C ./lib/my

re: fclean all
