/*
** EPITECH PROJECT, 2022
** talk
** File description:
** my_rpg
*/

#include "my_rpg.h"

void talk_to_png(global_t *global, sfRenderWindow *window)
{
    sfMouseButton space = sfKeySpace;
    if (global->map[0].map_txt[global->hero[0].y][global->hero[0].x] == 'o') {
        char *str = "The village has been attacked by a legion of slimes\nplease help us...";
        sfText *text = sfText_create();
        init_text((sfVector2f){380, 600}, str, text);
        if (global->speak[0].check_pos == 0)
            sfRenderWindow_drawSprite(window, global->house[0].space, NULL);
        if (sfKeyboard_isKeyPressed(space))
            global->speak[0].check_pos = 1;
        if (global->speak[0].check_pos == 1) {
            sfRenderWindow_drawSprite(window, global->speak[0].sprite, NULL);
            anim_speaker(global);
            sfRenderWindow_drawText(global->window, text, NULL);
        }
    } else
        global->speak[0].check_pos = 0;
    return;
}
