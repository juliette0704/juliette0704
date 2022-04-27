/*
** EPITECH PROJECT, 2022
** life.c
** File description:
** attack_hitbox
*/

#include "my_rpg.h"

void init_life(global_t *m)
{
    sfIntRect rect = {0, 0, 300, 45};
    m->life[0].rect = rect;
    sfVector2f pos = {0,-7};
    m->life[0].sprite = make_sprite("sprite/life/life.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setScale(m->life[i].sprite, (sfVector2f){1.5, 1.5});
        sfSprite_setTextureRect(m->life[i].sprite, rect);
        sfSprite_setPosition(m->life[i].sprite, pos);
    }
    return;
}

void draw_life_else(global_t *m)
{
    if (m->life[0].life == 4) {
        sfIntRect rect = {0, 123, 300, 42};
        m->life[0].rect = rect;
    }
    if (m->life[0].life == 5) {
        sfIntRect rect = {0, 84, 300, 42};
        m->life[0].rect = rect;
    }
    if (m->life[0].life == 6) {
        sfIntRect rect = {0, 48, 300, 42};
        m->life[0].rect = rect;
    }
    if (m->life[0].life == 7) {
        sfIntRect rect = {0, 8, 300, 42};
        m->life[0].rect = rect;
    }
}

void draw_life(global_t *m)
{
    int i = 0;
    if (m->life[0].life == 1) {
        sfIntRect rect = {0, 237, 300, 42};
        m->life[0].rect = rect;
    }
    if (m->life[0].life == 2) {
        sfIntRect rect = {0, 198, 300, 42};
        m->life[0].rect = rect;
    }
    if (m->life[0].life == 3) {
        sfIntRect rect = {0, 160, 300, 42};
        m->life[0].rect = rect;
    }
    draw_life_else(m);
    sfSprite_setTextureRect(m->life[0].sprite, m->life[0].rect);
    sfRenderWindow_drawSprite(m->window, m->life[0].sprite, NULL);
}