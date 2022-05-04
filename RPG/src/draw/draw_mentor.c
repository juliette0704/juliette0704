/*
** EPITECH PROJECT, 2021
** draw_mentor.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_mentor(global_t *g)
{
    g->mentor[0].speedmentor = 0;
    sfIntRect rect = {0, 0, 48, 48};
    g->mentor[0].rect = rect;
    sfVector2f pos = {1500,730};
    g->mentor[0].pos = pos;
    g->mentor[0].sprite = make_sprite("./sprite/el_mentor/mentor.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setTextureRect(g->mentor[0].sprite, g->mentor[0].rect);
        sfSprite_scale(g->mentor[0].sprite, (sfVector2f){2, 2});
        sfSprite_setPosition(g->mentor[i].sprite, pos);
    }
    g->mentor[0].clock = sfClock_create();
    return;
}

void init_rect_mentor(global_t *g)
{
    g->mentor[0].rect = (sfIntRect){0, 0, 48, 48};
    g->mentor[0].rect.left = g->mentor[0].speedmentor;
    sfSprite_setTextureRect(g->mentor[0].sprite, g->mentor[0].rect);
}

void anim_mentor(global_t *g)
{
    if (g->mentor[0].sec > 0.25) {
            init_rect_mentor(g);
            sfClock_restart(g->mentor[0].clock);
            if (g->mentor[0].speedmentor >= 140)
                    g->mentor[0].speedmentor = 0;
            else
                g->mentor[0].speedmentor += 48;
    }
    sfSprite_setPosition(g->mentor[0].sprite, g->mentor[0].pos);
    sfRenderWindow_drawSprite(g->window, g->mentor[0].sprite, NULL);
}