/*
** EPITECH PROJECT, 2022
** potion
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_potion(global_t *global)
{
    char *str[] = {"sprite/potion/potion_2.png", "sprite/potion/potion_1.png"};
    sfIntRect rect[] = {{1650, 175, 180, 180}, {1300, 175, 180, 180}};
    sfVector2f scale = {7, 7};
    sfVector2f pos[] = {{1540, 285}, {1427, 285}};
    global->potion[0].is_open = 0;
    for (int i = 0; i < 2; i++) {
        global->potion[i].is_pot = 0;
        global->potion[i].select = rect[i];
        global->potion[i].sprite = make_sprite(str[i]);
        sfSprite_setScale(global->potion[i].sprite, scale);
        sfSprite_setPosition(global->potion[i].sprite, pos[i]);
    }
    return;
}
