/*
** EPITECH PROJECT, 2022
** boss_door
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_boss_door(global_t *global)
{
    sfIntRect rect = {30, 0, 133, 300};
    global->labydoor[1].rect = rect;
    global->labydoor[1].sprite = make_sprite("sprite/door/door_boss.png");
    sfVector2f pos = {2750, 1310};
    global->labydoor[1].pos = pos;
    global->labydoor[1].speed = 0;
    global->labydoor[1].speed = 0;
    sfSprite_setTextureRect(global->labydoor[1].sprite, global->labydoor[1].rect);
    sfSprite_setPosition(global->labydoor[1].sprite, pos);
    float sec;
    sfClock *clock;
    global->labydoor[1].sec = sec;
    global->labydoor[1].clock = clock;
    global->labydoor[1].clock = sfClock_create();
    return;
}
