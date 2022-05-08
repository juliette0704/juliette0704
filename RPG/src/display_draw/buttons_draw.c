/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** buttons_draw
*/

#include "my_rpg.h"

void play_draw(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->button_play[1].sprite, sfFalse);
}

void tuto_draw(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->button_tuto[1].sprite, sfFalse);
}

void quit_draw(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->button_quit[1].sprite, sfFalse);
}