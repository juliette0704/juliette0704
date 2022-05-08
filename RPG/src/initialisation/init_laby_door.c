/*
** EPITECH PROJECT, 2021
** init_laby_door.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_laby_door(global_t *m)
{
    sfIntRect rect = {0, 0, 110.4, 300};
    m->labydoor[0].rect = rect;
    m->labydoor[0].sprite = make_sprite("sprite/door/door.png");
    sfVector2f pose = {3200,2020};
    m->labydoor[0].pos = pose;
    m->labydoor[0].speed = 0;
    for (int i = 0; i < 1; i++) {
        sfSprite_setTextureRect(m->labydoor[i].sprite, m->labydoor[i].rect);
        sfSprite_setPosition(m->labydoor[i].sprite, pose);
    }
    m->labydoor[0].clock = sfClock_create();
    return;
}

void init_rect_labydoor(global_t *m)
{
    m->labydoor[0].rect = (sfIntRect){0, 0, 110.4, 300};
    m->labydoor[0].rect.left = m->labydoor[0].speed;
    sfSprite_setTextureRect(m->labydoor[0].sprite, m->labydoor[0].rect);
}

void anim_labydoor(global_t *m)
{
    if (m->labydoor[0].sec > 0.25) {
        init_rect_labydoor(m);
        sfClock_restart(m->labydoor[0].clock);
        if (m->labydoor[0].speed >= 400)
            sfRenderWindow_drawSprite(m->window, m->labydoor[0].sprite, NULL);
        else
            m->labydoor[0].speed += 110.4;
    }
    sfSprite_setPosition(m->labydoor[0].sprite,m->labydoor[0].pos);
    sfRenderWindow_drawSprite(m->window, m->labydoor[0].sprite, NULL);
}

void draw_laby_door(global_t *m)
{
    sfSprite_setPosition(m->labydoor[0].sprite,m->labydoor[0].pos);
    sfRenderWindow_drawSprite(m->window, m->labydoor[0].sprite, NULL);
}