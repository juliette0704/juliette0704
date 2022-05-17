/*
** EPITECH PROJECT, 2022
** fire_particle
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_fire_particle(global_t *global)
{
    sfIntRect rect = {0, 0, 65, 100};
    sfVector2f pos[] = {{100, 100}, {800, 800}, {500, 200}, {1700, 500}, {1000, 100}};
    sfVector2f pos_magic[] = {{960, 540}, {860, 540}, {1060, 540}, {960, 440}, {960, 640}};
    float sec;
    sfClock *clock;
    global->particle[0].sec = sec;
    global->particle[0].clock = clock;
    global->particle[0].clock = sfClock_create();
    for (int i = 0; i < 5; i++) {
        global->particle[i].sprite = make_sprite("sprite/particle/fire_part.png");
        global->particle[i].pos = pos[i];
        global->particle[i].rect = rect;
    }
    for (int i = 5; i < 10; i++) {
        global->particle[i].sprite = make_sprite("sprite/particle/magic_part.png");
        global->particle[i].pos = pos_magic[i - 5];
        global->particle[i].rect = rect;
    }
    global->particle[0].is_magic = 0;
    return;
}

void fire_particle(global_t *global, int i)
{
    if (global->particle[0].sec > 0.3) {
        if (global->particle[0].rect.left < 150)
            global->particle[0].rect.left += 65;
        else {
            global->particle[0].rect.left = 0;
            global->particle[i].pos.x = rand() % 1850;
            global->particle[i].pos.y = rand() % 950;
        }
        sfSprite_setTextureRect(global->particle[i].sprite, global->particle[0].rect);
        sfClock_restart(global->particle[0].clock);
    }
    sfSprite_setPosition(global->particle[i].sprite, global->particle[i].pos);
    sfRenderWindow_drawSprite(global->window, global->particle[i].sprite, NULL);
    return;
}

void magic_particle(global_t *global, int i)
{
    if (global->particle[0].sec > 0.3) {
        if (global->particle[0].rect.left < 150)
            global->particle[0].rect.left += 65;
        else {
            global->particle[0].rect.left = 0;
            if (i == 9)
                global->particle[0].is_magic = 0;
        }
        sfSprite_setTextureRect(global->particle[i].sprite, global->particle[0].rect);
        sfClock_restart(global->particle[0].clock);
    }
    sfSprite_setPosition(global->particle[i].sprite, global->particle[i].pos);
    sfRenderWindow_drawSprite(global->window, global->particle[i].sprite, NULL);
    return;
}
