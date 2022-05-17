/*
** EPITECH PROJECT, 2021
** init_toucht.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_toucht(global_t *m)
{
    sfVector2f pos = {500,500};
    m->toucht[0].sprite = make_sprite("sprite/touch/touch.png");
    for (int i = 0; i < 1; i++) {
        // sfSprite_scale(m->toucht[0].sprite, (sfVector2f){-1.5, -1.5});
        sfSprite_setPosition(m->toucht[i].sprite, pos);
    }
    // init_text((sfVector2f){600, 500}, "hello", m);
    return;
}
