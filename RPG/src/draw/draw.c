/*
** EPITECH PROJECT, 2022
** draw
** File description:
** my_rpg
*/

#include "my_rpg.h"

void draw(sfRenderWindow *window, global_t *global)
{
    //sfRenderWindow_drawSprite(window, global->speak[0].sprite, NULL);
    // for (int i = 0; global->map[0].map_txt[i] != NULL; i++)
    //     sfRenderWindow_drawText(window, global->map[i].temp, NULL);

    // if (global->box[0].pos.y != 0)
        // sfSprite_setPosition(global->box[0].sprite, global->box[0].pos);

    sokoban(global);
    play_poster(global);
    draw_life(global);
    anim_fire(global);
    if (global->rain[0].sec > 20) {
        moov_rain(global);
        if (global->rain[0].sec > 30)
            sfClock_restart(global->rain[0].clock);
    }
    
    talk_to_png(global, window);
    draw_inventory(global);
    return;
}
