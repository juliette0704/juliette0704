/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** simple_font
*/

#include "my_rpg.h"

void init_behind_clouds(global_t *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos = {600, 0};
    global->behind_cloud.sprite = sfSprite_create();
    global->behind_cloud.texture = sfTexture_createFromFile("menu/Layers/cloud_lonely.png", NULL);
    global->behind_cloud.scale = scale;
    global->behind_cloud.pos = pos;
    sfSprite_setTexture(global->behind_cloud.sprite, global->behind_cloud.texture, sfTrue);
    sfSprite_setScale(global->behind_cloud.sprite, global->behind_cloud.scale);
    sfSprite_setPosition(global->behind_cloud.sprite, global->behind_cloud.pos);
}

void init_background(global_t *global)
{
    sfVector2f scale = {5, 5};
    global->font_blue.sprite = sfSprite_create();
    global->font_blue.texture = sfTexture_createFromFile("menu/Layers/sky_lightened.png", NULL);
    global->font_blue.scale = scale;
    sfSprite_setTexture(global->font_blue.sprite, global->font_blue.texture, sfTrue);
    sfSprite_setScale(global->font_blue.sprite, global->font_blue.scale);
}