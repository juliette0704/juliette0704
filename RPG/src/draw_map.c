/*
** EPITECH PROJECT, 2022
** draw_map
** File description:
** my_rpg
*/

#include "my_rpg.h"

void draw_map(sfRenderWindow *window, global_t *global)
{
    sfVector2f temp = {0, 0};
    int cont = 0;
    for (int i = 0; global->map[0].map_txt[i] != NULL; i++) {
        for (int j = 0; global->map[0].map_txt[i][j] != '\0'; j++) {
            sfSprite_setPosition(global->pixel[cont].sprite, temp);
            sfRenderWindow_drawSprite(window, global->pixel[cont].sprite, NULL);
            temp.x += 143;
            cont++;
        }
        temp.x = 0;
        temp.y += 143;
    }
    return;
}
