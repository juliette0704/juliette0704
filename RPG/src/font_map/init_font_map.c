/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** init_font_map
*/

#include "my_rpg.h"

void init_mountains(global_t *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos[] = {{0, 30}, {1535, 30}, {3070, 30}};
    for (int i = 0; i < 3; i++) {
        global->mountains[i].sprite = sfSprite_create();
        global->mountains[i].texture = sfTexture_createFromFile("menu/Layers/glacial_mountains.png", NULL);
        global->mountains[i].scale = scale;
        global->mountains[i].pos = pos[i];
        sfSprite_setTexture(global->mountains[i].sprite, global->mountains[i].texture, sfTrue);
        sfSprite_setScale(global->mountains[i].sprite, global->mountains[i].scale);
        sfSprite_setPosition(global->mountains[i].sprite, global->mountains[i].pos);
    }
}

void init_big_clouds(global_t *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos[] = {{0, 0}, {1535, 0}, {3070, 0}};
    for (int i = 0; i < 3; i++) {
        global->big_cloud[i].sprite = sfSprite_create();
        global->big_cloud[i].texture = sfTexture_createFromFile("menu/Layers/clouds_bg.png", NULL);
        global->big_cloud[i].scale = scale;
        global->big_cloud[i].pos = pos[i];
        sfSprite_setTexture(global->big_cloud[i].sprite, global->big_cloud[i].texture, sfTrue);
        sfSprite_setScale(global->big_cloud[i].sprite, global->big_cloud[i].scale);
        sfSprite_setPosition(global->big_cloud[i].sprite, global->big_cloud[i].pos);
    }
}

void init_fine_clouds(global_t *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos[] = {{0, 100}, {1535, 100}, {3070, 100}};
    for (int i = 0; i < 3; i++) {
        global->fine_cloud[i].sprite = sfSprite_create();
        global->fine_cloud[i].texture = sfTexture_createFromFile("menu/Layers/clouds_mg_3.png", NULL);
        global->fine_cloud[i].scale = scale;
        global->fine_cloud[i].pos = pos[i];
        sfSprite_setTexture(global->fine_cloud[i].sprite, global->fine_cloud[i].texture, sfTrue);
        sfSprite_setScale(global->fine_cloud[i].sprite, global->fine_cloud[i].scale);
        sfSprite_setPosition(global->fine_cloud[i].sprite, global->fine_cloud[i].pos);
    }
}

void init_multiple_clouds(global_t *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos[] = {{0, 150}, {1535, 150}, {3070, 150}};
    for (int i = 0; i < 3; i++) {
        global->multiple_clouds[i].sprite = sfSprite_create();
        global->multiple_clouds[i].texture = sfTexture_createFromFile("menu/Layers/clouds_mg_2.png", NULL);
        global->multiple_clouds[i].scale = scale;
        global->multiple_clouds[i].pos = pos[i];
        sfSprite_setTexture(global->multiple_clouds[i].sprite, global->multiple_clouds[i].texture, sfTrue);
        sfSprite_setScale(global->multiple_clouds[i].sprite, global->multiple_clouds[i].scale);
        sfSprite_setPosition(global->multiple_clouds[i].sprite, global->multiple_clouds[i].pos);
    }
}

void init_front_clouds(global_t *global)
{
    sfVector2f scale = {4, 4};
    sfVector2f pos[] = {{0, 165}, {1535, 165}, {3070, 165}};
    for (int i = 0; i < 3; i++) {
        global->front_clouds[i].sprite = sfSprite_create();
        global->front_clouds[i].texture = sfTexture_createFromFile("menu/Layers/clouds_mg_1.png", NULL);
        global->front_clouds[i].scale = scale;
        global->front_clouds[i].pos = pos[i];
        sfSprite_setTexture(global->front_clouds[i].sprite, global->front_clouds[i].texture, sfTrue);
        sfSprite_setScale(global->front_clouds[i].sprite, global->front_clouds[i].scale);
        sfSprite_setPosition(global->front_clouds[i].sprite, global->front_clouds[i].pos);
    }
}