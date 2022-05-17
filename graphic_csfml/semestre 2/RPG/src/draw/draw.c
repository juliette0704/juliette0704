/*
** EPITECH PROJECT, 2022
** draw
** File description:
** my_rpg
*/

#include "my_rpg.h"

void draw(sfRenderWindow *window, global_t *global)
{
    play_poster(global);
    anim_fire(global);
    if (global->rain[0].sec > 20) {
        moov_rain(global);
        if (global->rain[0].sec > 30)
            sfClock_restart(global->rain[0].clock);
    }
    talk_to_png(global, window);
    draw_inventory(global);
    draw_quest(global);            
    return;
}
