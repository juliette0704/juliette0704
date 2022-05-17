/*
** EPITECH PROJECT, 2021
** initialization
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_speaker(global_t *g)
{
    g->speaker[0].speedspeak = 144;
    sfIntRect rect = {0, 0, 144, 50};
    g->speaker[0].rect = rect;
    sfVector2f pos = {50,570};
    g->speaker[0].sprite = make_sprite("./sprite/speaker/face.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_scale(g->speaker[0].sprite, (sfVector2f){2, 2});
        sfSprite_setPosition(g->speaker[i].sprite, pos);
    }
    g->speaker[0].clock = sfClock_create();
    return;
}

void init_rect_speaker(global_t *g)
{
    g->speaker[0].rect = (sfIntRect){0, 0, 144, 130};
    g->speaker[0].rect.left = g->speaker[0].speedspeak;
    sfSprite_setTextureRect(g->speaker[0].sprite, g->speaker[0].rect);
}

void anim_speaker(global_t *g)
{
    if (g->speaker[0].sec > 0.25) {
        init_rect_speaker(g);
        sfClock_restart(g->speaker[0].clock);
        if (g->speaker[0].speedspeak >= 300)
            g->speaker[0].speedspeak = 144;
        else
            g->speaker[0].speedspeak += 144;
    }
    sfRenderWindow_drawSprite(g->window, g->speaker[0].sprite, NULL);
}
