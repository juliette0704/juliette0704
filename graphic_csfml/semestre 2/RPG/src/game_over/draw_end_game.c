/*
** EPITECH PROJECT, 2022
** draw_end_game
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_end_game(global_t *global)
{
    global->intro[2].sprite = make_sprite("sprite/end/end_game.png");
    global->intro[2].is_done = 0;
    sfColor color = sfSprite_getColor(global->intro[2].sprite);
    color.a = 2;
    sfSprite_setColor(global->intro[2].sprite, color);
    return;
}

void draw_end_game(global_t *global)
{
    sfMouseButton x = sfKeyX;
    sfColor color = sfSprite_getColor(global->intro[2].sprite);
    if (global->intro[0].sec > 0.01) {
        if (color.a < 250)
            color.a += 1;
        if (sfKeyboard_isKeyPressed(x)) {
            global->scene = 0;
        }
        sfClock_restart(global->intro[0].clock);
    }
    sfSprite_setColor(global->intro[2].sprite, color);
    sfRenderWindow_drawSprite(global->window, global->intro[2].sprite, NULL);
    return;
}
