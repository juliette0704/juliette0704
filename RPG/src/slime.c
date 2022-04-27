/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init slime
*/

#include "my_rpg.h"

void init_slime(global_t *global)
{
    global->enemy[0].stage = 0;
    sfClock *clock;
    float sec;
    global->enemy[0].sec = sec;
    global->enemy[0].clock = clock;
    global->enemy[0].clock = sfClock_create();
    sfIntRect rect = {0, 0, 32, 32};
    sfVector2f pos = {1200, 600};
    sfVector2f scale = {6, 6};
    sfVector2f origin = {16, 16};
    global->enemy[0].rect = rect;
    global->enemy[0].pos = pos;
    global->enemy[0].scale = scale;
    global->enemy[0].sprite = make_sprite("sprite/hero/slimeNRV.png");
    sfSprite_setTextureRect(global->enemy[0].sprite, rect);
    sfSprite_setPosition(global->enemy[0].sprite, pos);
    sfSprite_setScale(global->enemy[0].sprite, scale);
    sfSprite_setOrigin(global->enemy[0].sprite, origin);
    return;
}

void idle_slime(global_t *global)
{
    global->enemy[0].rect.top = 0;
    sfSprite_setPosition(global->enemy[0].sprite, global->enemy[0].pos);
    if (global->enemy[0].sec > 0.15) {
        if (global->enemy[0].rect.left < 90)
            global->enemy[0].rect.left += 32;
        else {
            global->enemy[0].rect.left = 0;
            global->enemy[0].stage = 1;
        }
        sfSprite_setTextureRect(global->enemy[0].sprite, global->enemy[0].rect);
        sfClock_restart(global->enemy[0].clock);
    }
    return;
}

void idle2_slime(global_t *global)
{
    global->enemy[0].rect.top = 32;
    sfSprite_setPosition(global->enemy[0].sprite, global->enemy[0].pos);
    if (global->enemy[0].sec > 0.15) {
        if (global->enemy[0].rect.left < 160)
            global->enemy[0].rect.left += 32;
        else {
            global->enemy[0].rect.left = 0;
            global->enemy[0].stage = 2;
        }
        sfSprite_setTextureRect(global->enemy[0].sprite, global->enemy[0].rect);
        sfClock_restart(global->enemy[0].clock);
    }
    return;
}

void attack_slime(global_t *global)
{
    global->enemy[0].rect.top = 64;
    sfSprite_setPosition(global->enemy[0].sprite, global->enemy[0].pos);
    if (global->enemy[0].sec > 0.1) {
        if (global->enemy[0].rect.left < 190) {
            global->enemy[0].rect.left += 32;
            global->enemy[0].pos.x += ((1010- global->enemy[0].pos.x) / 7);
            global->enemy[0].pos.y += ((605 - global->enemy[0].pos.y) / 7);
        } else {
            global->enemy[0].rect.left = 0;
            global->enemy[0].stage = 0;
        }
        sfSprite_setTextureRect(global->enemy[0].sprite, global->enemy[0].rect);
        sfClock_restart(global->enemy[0].clock);
    }
    return;
}

void slime_hit(global_t *global)
{
    global->enemy[0].rect.top = 96;
    sfSprite_setPosition(global->enemy[0].sprite, global->enemy[0].pos);
    if (global->enemy[0].sec > 0.15) {
        if (global->enemy[0].rect.left < 120)
            global->enemy[0].rect.left += 32;
        else {
            global->enemy[0].rect.left = 0;
            global->enemy[0].stage = 2;
        }
        sfSprite_setTextureRect(global->enemy[0].sprite, global->enemy[0].rect);
        sfClock_restart(global->enemy[0].clock);
    }
    return;
}

void animation_slime(global_t *global)
{
    sfVector2f scale_left = {6, 6};
    sfVector2f scale_right = {-6, 6};
    if (global->enemy[0].pos.x < 1010) 
        sfSprite_setScale(global->enemy[0].sprite, scale_left);
    else
        sfSprite_setScale(global->enemy[0].sprite, scale_right);
    if (global->enemy[0].stage == 0)
        idle_slime(global);
    else if (global->enemy[0].stage == 1)
        idle2_slime(global);
    else if (global->enemy[0].stage == 2)
        attack_slime(global);
    else if (global->enemy[0].stage == 3)
        slime_hit(global);
}