/*
** EPITECH PROJECT, 2022
** end_game
** File description:
** my_rpg
*/

#include "my_rpg.h"

void end_game(global_t *global)
{
    sfRenderWindow_close(global->window);
    sfSprite_destroy(global->pause_menu[0].sprite);
    sfSprite_destroy(global->pause_menu[0].resume);
    sfSprite_destroy(global->pause_menu[0].quit);
    sfSprite_destroy(global->pause_menu[0].option);
    sfSprite_destroy(global->intro[0].sprite);
    sfSprite_destroy(global->speak[0].sprite);
    sfSprite_destroy(global->speak[0].sprite_button);
    sfSprite_destroy(global->speak[0].hero);
    global->my_exit = 1;
    return;
}
