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
		src/initialisation/initialization.c	\
		src/launch/start_game.c	\
		src/draw/draw.c	\
		src/tools/tools.c	\
		src/animation/animation_mouv.c	\
		src/animation/talk.c	\
		src/hero/deplace_hero.c	\
		src/draw/draw_map.c	\
		src/menu/menu.c    \
		src/animation/rain.c    \
		src/animation/speaker.c    \
		src/launch/start_map.c	\
		src/draw/draw_house.c	\
		src/draw/draw_poster.c	\
		src/ennemis/slime.c	\
		src/ennemis/hitbox_attack_hero.c	\
		src/cursor/cursor.c	\
		src/save/save_to_struct.c    \
		src/save/life.c    \
		src/animation/fire_life.c    \
		src/sokoban/box.c    \
		src/initialisation/init_touch.c    \
		src/draw/draw_inventory.c	\
		src/draw/draw_dungeon.c    \
		src/draw/draw_intro.c	\
		src/launch/tutorial.c    \
		src/launch/island.c    \
		src/animation/shield.c    \
		src/game_over/game_over.c	\
		src/draw/draw_pause.c	\
		src/end_game/end_game.c	\
		src/draw/draw_arena.c	\
		src/ennemis/boss_slime.c	\
		src/draw/draw_mentor.c    \
		src/initialisation/init_bubble_speak.c    \
		src/draw/draw_minispace.c    \
		src/initialisation/init_light.c    \
		src/potion/potion.c	\
		src/draw/draw_final.c	\
		src/initialisation/init_laby_door.c    \
		src/editing_buttons/init_buttons.c		\
		src/font_map/init_font_map.c		\
		src/font_map/init_special.c		\
		src/display_draw/draw.c		\
		src/launch_menu/init.c		\
		src/event/event_buttons.c		\
		src/event/event_menu.c		\
		src/display_draw/buttons_draw.c		\
		src/font_map/simple_font.c			\
		src/display_draw/condition.c		\
		src/font_map/title.c			\
		src/animation/boss_door.c	\
		src/game_over/draw_end_game.c	\
		src/particle/fire_particle.c	\
		src/initialisation/init_quest.c    \
		src/music/music.c	\

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
