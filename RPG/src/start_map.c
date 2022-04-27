/*
** EPITECH PROJECT, 2022
** start_map
** File description:
** my_rpg
*/

#include "my_rpg.h"

void door_animation(sfSprite *door, sfVector2f pos, global_t *global, int i)
{
    if (global->door[0].sec > 0.3) {
        if (global->door[0].rect.left < 180)
            global->door[0].rect.left += 48;
        else {
            global->scene = i;
            global->door[0].rect.left = 0;
        }
        sfSprite_setTextureRect(door, global->door[0].rect);
        sfSprite_setPosition(door, pos);
        sfClock_restart(global->door[0].clock);
    }
    return;
}

void open_door(sfRenderWindow *window, global_t *global)
{
    sfMouseButton space = sfKeySpace;
    global->door[0].sec = make_clock(global->door[0].clock);
    switch (global->map[0].map_txt[global->hero[0].y][global->hero[0].x]) {
        case '1' :
            sfRenderWindow_drawSprite(window, global->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space))
                global->house[0].is_open = 1;
            if (global->house[0].is_open == 1) {
                door_animation(global->door[0].sprite, global->door[0].pos, global, 1);
                sfRenderWindow_drawSprite(window, global->door[0].sprite, NULL);
            }
            break;
        case '2' :
            sfRenderWindow_drawSprite(window, global->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space))
                global->house[1].is_open = 1;
            if (global->house[1].is_open == 1) {
                door_animation(global->door[1].sprite, global->door[1].pos, global, 2);
                sfRenderWindow_drawSprite(window, global->door[1].sprite, NULL);
            }
            break;
        default :
            break;
    }
    return;
}

void start_map(sfRenderWindow *window, global_t *global)
{
    deplace_in_map(global->window, global);
    sfSprite_setTextureRect(global->map[0].sprite, global->map[0].my_view);
    sfRenderWindow_drawSprite(window, global->map[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, global->map[0].front, NULL);
    sfRenderWindow_drawSprite(window, global->enemy[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, global->png_crest[0].sprite, NULL);
    sfRenderWindow_drawSprite(window, global->hero[global->hero[0].check_mouv].sprite, NULL);
    sfRenderWindow_drawSprite(window, global->map[0].back, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(window, global->hit_attack[i].sprite, NULL);
    sfRenderWindow_drawSprite(window, global->cursor.sprite, NULL);
    open_door(window, global);
    draw(global->window, global);
    return;
}
