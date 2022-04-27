/*
** EPITECH PROJECT, 2022
** draw
** File description:
** my_rpg
*/

#include "my_rpg.h"

void draw(sfRenderWindow *window, global_t *global)
{
    talk_to_png(global, window);
    //sfRenderWindow_drawSprite(window, global->speak[0].sprite, NULL);
    // for (int i = 0; global->map[0].map_txt[i] != NULL; i++)
    //     sfRenderWindow_drawText(window, global->map[i].temp, NULL);
    play_poster(global);
    draw_life(global);
    if (global->rain[0].sec > 20) {
        moov_rain(global);
        if (global->rain[0].sec > 30)
            sfClock_restart(global->rain[0].clock);
    }
    sfRenderWindow_display(window);
    return;
}
