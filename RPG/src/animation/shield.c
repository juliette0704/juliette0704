/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** water_shield
*/

#include "my_rpg.h"

void init_shield(global_t *global)
{
    global->shield[0].active = 0;
    global->shield[0].duration = 6;
    sfClock *clock;
    float sec;
    global->shield[0].sec = sec;
    global->shield[0].clock = clock;
    global->shield[0].clock = sfClock_create();
    global->shield[0].sec_cd = sec;
    global->shield[0].clock_cd = clock;
    global->shield[0].clock_cd = sfClock_create();
    sfIntRect rect = {0, 0, 155, 155};
    sfVector2f pos = {939.5, 525};
    sfVector2f scale = {0.9, 0.9};
    sfVector2f origin = {77.5, 77.5};
    global->shield[0].cd = 0;
    global->shield[0].rect = rect;
    global->shield[0].sprite = make_sprite("sprite/hero/bubble_shield.png");
    global->shield[1].sprite = make_sprite("sprite/hero/end_shield.png");
    for (int i = 0; i < 2; i++) {
        sfSprite_setTextureRect(global->shield[i].sprite, rect);
        sfSprite_setPosition(global->shield[i].sprite, pos);
        sfSprite_setScale(global->shield[i].sprite, scale);
    }
    return;
}

void shield_active(global_t *global)
{
    if (global->shield[0].sec > 0.15) {
        if (global->shield[0].rect.left < 100)
            global->shield[0].rect.left += 155;
        else {
            global->shield[0].rect.left = 0;
            global->shield[0].active++;
        }
        sfSprite_setTextureRect(global->shield[0].sprite, global->shield[0].rect);
        sfClock_restart(global->shield[0].clock);
    }
    return;
}

void shield_ending(global_t *global)
{
    if (global->shield[0].sec > 0.1) {
        if (global->shield[0].rect.left < 800)
            global->shield[0].rect.left += 155;
        else {
            global->shield[0].rect.left = 0;
            global->shield[0].active = 0;
        }
        sfSprite_setTextureRect(global->shield[1].sprite, global->shield[0].rect);
        sfClock_restart(global->shield[0].clock);
    }
    return;
}

void animation_shield(global_t *global)
{
    if (global->shield[0].active <= global->shield[0].duration && global->shield[0].active != 0)
        shield_active(global);
    else if (global->shield[0].active > global->shield[0].duration)
        shield_ending(global);
    return;
}

void draw_shield(global_t *global)
{
    if (global->shield[0].active <= global->shield[0].duration && global->shield[0].active != 0)
        sfRenderWindow_drawSprite(global->window, global->shield[0].sprite, sfFalse);
    else if (global->shield[0].active > global->shield[0].duration)
        sfRenderWindow_drawSprite(global->window, global->shield[1].sprite, sfFalse);
    return;
}
