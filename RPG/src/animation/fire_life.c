/*
** EPITECH PROJECT, 2021
** fire_life.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_fire(global_t *g)
{
    g->fire[0].speedfire = 48;
    sfIntRect rect = {0, 0, 48, 48};
    g->fire[0].rect = rect;
    sfVector2f pos = {50,570};
    g->fire[0].sprite = make_sprite("./sprite/fire/fire.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setTextureRect(g->fire[0].sprite, g->fire[0].rect);
        sfSprite_scale(g->fire[0].sprite, (sfVector2f){2, 2});
        sfSprite_setPosition(g->fire[i].sprite, pos);
    }
    g->fire[0].clock = sfClock_create();
    return;
}

void init_rect_fire(global_t *g)
{
    g->fire[0].rect = (sfIntRect){0, 0, 48, 48};
    g->fire[0].rect.left = g->fire[0].speedfire;
    sfSprite_setTextureRect(g->fire[0].sprite, g->fire[0].rect);
}

void anim_fire(global_t *g)
{
    if (g->fire[0].sec > 0.125) {
            init_rect_fire(g);
            sfClock_restart(g->fire[0].clock);
            if (g->fire[0].speedfire >= 143)
                    g->fire[0].speedfire = 0;
            else
                g->fire[0].speedfire += 48;
    }
    sfRenderWindow_drawSprite(g->window, g->fire[0].sprite, NULL);
}
