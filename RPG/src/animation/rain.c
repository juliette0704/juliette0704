/*
** EPITECH PROJECT, 2022
** rain.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_black(global_t *m)
{
    sfVector2f pos = {0,0};
    m->rain[0].spriteblack = make_sprite("sprite/weather/noir.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_scale(m->rain[0].spriteblack, (sfVector2f){2, 2});
        sfSprite_setPosition(m->rain[i].spriteblack, pos);
    }
    return;
}

void init_rain(global_t *m)
{
    init_black(m);
    m->rain[0].speedrain = 4000;
    sfIntRect rect = {2, 0, 2000, 1080};
    m->rain[0].rect = rect;
    sfVector2f pos = {0,0};
    m->rain[0].sprite = make_sprite("sprite/weather/rain.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setTextureRect(m->rain[i].sprite, rect);
        sfSprite_setPosition(m->rain[i].sprite, pos);
    }
    m->rain[0].clock = sfClock_create();
    return;
}

void init_rect_rain(global_t *m)
{
    int y = m->rain[0].speedrain;
    m->rain[0].rect = (sfIntRect){0, y, 2000, 1080};
    m->rain[0].rect.height = m->rain[0].speedrain;
    sfSprite_setTextureRect(m->rain[0].sprite, m->rain[0].rect);
}

void moov_rain(global_t *g)
{
    if (g->rain[0].sec > 0.005) {
        init_rect_rain(g);
        // sfClock_restart(g->rain[0].clock);
        if (g->rain[0].speedrain <= 1000)
            g->rain[0].speedrain = 2500;
        else
            g->rain[0].speedrain -= 20;
    }
    sfRenderWindow_drawSprite(g->window, g->rain[0].spriteblack, NULL);
    sfRenderWindow_drawSprite(g->window, g->rain[0].sprite, NULL);
}