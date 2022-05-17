/*
** EPITECH PROJECT, 2022
** life.c
** File description:
** attack_hitbox
*/

#include "my_rpg.h"

void init_life(global_t *m)
{
    sfIntRect rect = {0, 0, 800, 45};
    m->life[0].rect = rect;
    sfVector2f pos = {20, 20};
    char *str[] = {"sprite/life/life_10.png", "sprite/life/life_9.png",
    "sprite/life/life_8.png", "sprite/life/life_7.png", "sprite/life/life_6.png",
    "sprite/life/life_5.png", "sprite/life/life_4.png", "sprite/life/life_3.png",
    "sprite/life/life_2.png", "sprite/life/life_1.png"};
    for (int i = 0; i < 10; i++) {
        m->life[i].sprite = make_sprite(str[i]);
        sfSprite_setScale(m->life[i].sprite, (sfVector2f){1.5, 1.5});
        sfSprite_setTextureRect(m->life[i].sprite, rect);
        sfSprite_setPosition(m->life[i].sprite, pos);
    }
    return;
}

void draw_life(global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->life[m->life[0].life].sprite, NULL);
}