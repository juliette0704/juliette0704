/*
** EPITECH PROJECT, 2021
** init_light.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_light(global_t *m)
{
    sfVector2f pos = {0,0};
    m->light[0].sprite = make_sprite("sprite/light.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setPosition(m->light[i].sprite, pos);
    }
}