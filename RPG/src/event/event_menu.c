/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** event_menu
*/

#include "my_rpg.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left >= max_value)
        rect->left = 0;
    rect->left += offset;
    return;
}

void animate_bird(global_t *global)
{
    for (int i = 0; i < 10; i++) {
        if (global->sec_bird > 0.05) {
            global->bird[i].pos.x -= global->bird[i].haste;
            move_rect(&global->bird[i].rect, 16, 90);
            sfSprite_setPosition(global->bird[i].sprite, global->bird[i].pos);
            sfSprite_setTextureRect(global->bird[i].sprite, global->bird[i].rect);
            reset_position(global);
            sfClock_restart(global->clock_bird);
        }
    }
    return;
}

void change_position(global_t *global)
{
    animate_bird(global);
    if (global->sec_menu > 0.01) {
        global->behind_cloud.pos.x -= 0.2;
        sfSprite_setPosition(global->behind_cloud.sprite, global->behind_cloud.pos);
        for (int i = 0; i < 3; i++) {
            global->big_cloud[i].pos.x -= 0.1;
            global->fine_cloud[i].pos.x -= 0.15;
            global->front_clouds[i].pos.x -= 0.1;
            global->multiple_clouds[i].pos.x -= 0.2;
            sfSprite_setPosition(global->big_cloud[i].sprite, global->big_cloud[i].pos);
            sfSprite_setPosition(global->fine_cloud[i].sprite, global->fine_cloud[i].pos);
            sfSprite_setPosition(global->front_clouds[i].sprite, global->front_clouds[i].pos);
            sfSprite_setPosition(global->multiple_clouds[i].sprite, global->multiple_clouds[i].pos);
        }
        sfClock_restart(global->clock_menu);
    }
    return;
}

void reset_position(global_t *global)
{
    for (int i = 0; i < 10; i++) {
        if (global->bird[i].pos.x < -20) {
            global->bird[i].pos.x = (rand() % 1980) + 1980;
            global->bird[i].pos.y = rand() % 400;
            sfSprite_setPosition(global->bird[i].sprite, global->bird[i].pos);
        }
    }
    for (int i = 0; i < 3; i++) {
        if (global->big_cloud[i].pos.x < -1535) {
            global->big_cloud[i].pos.x = 3070;
            sfSprite_setPosition(global->big_cloud[i].sprite, global->big_cloud[i].pos);
        }
        if (global->fine_cloud[i].pos.x < -1535) {
            global->fine_cloud[i].pos.x = 3070;
            sfSprite_setPosition(global->fine_cloud[i].sprite, global->fine_cloud[i].pos);
        }
        if (global->multiple_clouds[i].pos.x < -1535) {
            global->multiple_clouds[i].pos.x = 3070;
            sfSprite_setPosition(global->multiple_clouds[i].sprite, global->multiple_clouds[i].pos);
        }
        if (global->front_clouds[i].pos.x < -1535) {
            global->front_clouds[i].pos.x = 3070;
            sfSprite_setPosition(global->front_clouds[i].sprite, global->front_clouds[i].pos);
        }
    }
    if (global->behind_cloud.pos.x < -1200) {
        global->behind_cloud.pos.x = 1200;
        sfSprite_setPosition(global->behind_cloud.sprite, global->behind_cloud.pos);
    }
    return;
}