/*
** EPITECH PROJECT, 2021
** island.c
** File description:
** my_hunter
*/

#include "my_rpg.h"

void init_island(global_t *m)
{
    m->hero[2].x = 1;
    m->hero[2].y = 1;
    sfVector2f pos = {0,0};
    m->island[0].sprite = make_sprite("sprite/island/island.png");
    m->map[2].front = make_sprite("sprite/island/island2.png");
    sfSprite_scale(m->map[2].front, (sfVector2f){2, 2});
    for (int i = 0; i < 1; i++) {
        sfSprite_scale(m->island[0].sprite, (sfVector2f){2, 2});
    }
    return;
}
