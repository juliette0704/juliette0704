/*
** EPITECH PROJECT, 2021
** fire_life.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_fire(global_t *g)
{
    g->fire[0].speedfire = 144;
    sfIntRect rect = {0, 0, 144, 50};
    g->fire[0].rect = rect;
    sfVector2f pos = {50,570};
    g->fire[0].sprite = make_sprite("./sprite/fire/fire.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_scale(g->fire[0].sprite, (sfVector2f){2, 2});
        sfSprite_setPosition(g->fire[i].sprite, pos);
    }
    g->fire[0].clock = sfClock_create();
    return;
}

void init_rect_speaker(global_t *g)
{
    g->fire[0].rect = (sfIntRect){0, 0, 144, 130};
    g->fire[0].rect.left = g->fire[0].speedfire;
    sfSprite_setTextureRect(g->fire[0].sprite, g->fire[0].rect);
}

void anim_speaker(global_t *g)
{
    if (g->fire[0].sec > 0.25) {
        init_rect_speaker(g);
        sfClock_restart(g->fire[0].clock);
        if (g->fire[0].speedfire >= 300)
            g->fire[0].speedfire = 144;
        else
            g->fire[0].speedfire += 144;
    }
    sfRenderWindow_drawSprite(g->window, g->fire[0].sprite, NULL);
}