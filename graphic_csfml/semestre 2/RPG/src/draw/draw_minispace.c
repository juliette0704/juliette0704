/*
** EPITECH PROJECT, 2021
** draw_minispace.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_minispace(global_t *m)
{
    sfVector2f pos = {1400,236};
    m->minispace[0].sprite = make_sprite("sprite/touch/minispace.png");
    for (int i = 0; i < 1; i++) {
        // sfSprite_scale(m->panel[0].sprite, (sfVector2f){10, 10});
        sfSprite_setPosition(m->minispace[i].sprite, pos);
    }
    return;
}
