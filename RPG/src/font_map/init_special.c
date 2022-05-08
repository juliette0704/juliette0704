/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** init_special
*/

#include "my_rpg.h"

void init_birds(global_t *global)
{
    sfVector2f scale = {1, 1};
    sfIntRect rect = {0, 17, 16, 20};
    sfVector2f pos = {1980, 200};
    for (int i = 0; i < 10; i++) {
        global->bird[i].sprite = sfSprite_create();
        global->bird[i].texture = sfTexture_createFromFile("Bird/BirdSprite.png", NULL);
        global->bird[i].scale = scale;
        global->bird[i].rect = rect;
        global->bird[i].pos = pos;
        pos.x = rand() % 1980;
        pos.y = rand() % 400;
        global->bird[i].haste = (rand() % 5) + 1;
        sfSprite_setTexture(global->bird[i].sprite, global->bird[i].texture, sfTrue);
        sfSprite_setTextureRect(global->bird[i].sprite, global->bird[i].rect);
        sfSprite_setScale(global->bird[i].sprite, global->bird[i].scale);
        sfSprite_setPosition(global->bird[i].sprite, global->bird[i].pos);
    }
}