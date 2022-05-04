/*
** EPITECH PROJECT, 2022
** draw_intro
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_intro(global_t *global)
{
    global->intro[0].sprite = make_sprite("sprite/intro/solaria.png");
    float sec;
    sfClock *clock;
    global->intro[0].is_done = 0;
    sfColor color = sfSprite_getColor(global->intro[0].sprite);
    color.a = 1;
    sfSprite_setColor(global->intro[0].sprite, color);
    global->intro[0].sec = sec;
    global->intro[0].clock = clock;
    global->intro[0].clock = sfClock_create();
    return;
}

void draw_intro(global_t *global)
{
    sfColor color = sfSprite_getColor(global->intro[0].sprite); //0 255
    if (global->intro[0].sec > 0.01) {
        if (global->intro[0].is_done == 0)
            color.a += 1;
        if (color.a == 250)
            global->intro[0].is_done = 1;
        if (global->intro[0].is_done == 1)
            color.a -= 1;
        if (color.a == 0)
            global->scene = 0;
        sfClock_restart(global->intro[0].clock);
    }
    sfSprite_setColor(global->intro[0].sprite, color);
    sfRenderWindow_drawSprite(global->window, global->intro[0].sprite, NULL);
    return;
}
