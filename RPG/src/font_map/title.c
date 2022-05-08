/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** title
*/

#include "my_rpg.h"

void init_title(global_t *global)
{
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pos = {470, 80};
    global->title.sprite = sfSprite_create();
    global->title.texture = sfTexture_createFromFile("menu/solaria.png", NULL);
    global->title.scale = scale;
    global->title.pos = pos;
    sfSprite_setTexture(global->title.sprite, global->title.texture, sfTrue);
    sfSprite_setScale(global->title.sprite, global->title.scale);
    sfSprite_setPosition(global->title.sprite, global->title.pos);
}