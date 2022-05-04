/*
** EPITECH PROJECT, 2022
** animation_mouv
** File description:
** my_rpg
*/

#include "my_rpg.h"

void move_png_crest(sfRenderWindow *window, global_t *global, int i)
{
    if (global->png_crest[0].sec > 0.2) {
        if (global->png_crest[0].rect.left < 100)
            global->png_crest[0].rect.left += 48;
        else
            global->png_crest[0].rect.left = 2;
        sfSprite_setTextureRect(global->png_crest[i].sprite, global->png_crest[0].rect);
        sfClock_restart(global->png_crest[0].clock);
    }
    return;
}

void move(sfRenderWindow *window, global_t *global, int i)
{
    if (global->hero[0].sec > 0.2) {
        if (global->hero[0].rect.left < 100)
            global->hero[0].rect.left += 48;
        else
            global->hero[0].rect.left = 0;
        sfSprite_setTextureRect(global->hero[i].sprite, global->hero[0].rect);
        sfClock_restart(global->hero[0].clock);
    }
    return;
}

void attack(sfRenderWindow *window, global_t *global, int i)
{
    if (global->hero[0].sec > 0.075) {
        if (global->hero[0].rect_attack.left < 400)
            global->hero[0].rect_attack.left += 144;
        else {
            global->hero[0].check_attack = 0;
            global->hero[0].check_idle = global->hero[0].check_mouv - 8;
        }
        sfSprite_setTextureRect(global->hero[i].sprite, global->hero[0].rect_attack);
        sfClock_restart(global->hero[0].clock);
    }
    return;
}

void move_sprint(sfRenderWindow *window, global_t *global, int i)
{
    if (global->hero[0].sec > 0.1) {
        if (global->hero[0].rect.left < 100)
            global->hero[0].rect.left += 48;
        else
            global->hero[0].rect.left = 0;
        sfSprite_setTextureRect(global->hero[i].sprite, global->hero[0].rect);
        sfClock_restart(global->hero[0].clock);
    }
    return;
}