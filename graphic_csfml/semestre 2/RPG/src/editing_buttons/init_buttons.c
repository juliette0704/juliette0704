/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** init_buttons
*/

#include "my_rpg.h"

void init_button_play(global_t *global)
{
    char *path[] = {"buttons/ga_blue.png", "buttons/ga_purple.png"};
    sfVector2f scale = {0.4, 0.4};
    sfIntRect rect = {185, 200, 500, 225};
    sfVector2f pos = {850, 565};
    sfIntRect hitbox = {pos.x, pos.y, 200, 90};
    for (int i = 0; i < 2; i++) {
        global->button_play[i].sprite = sfSprite_create();
        global->button_play[i].texture = sfTexture_createFromFile(path[i], NULL);
        global->button_play[i].rect = hitbox;
        sfSprite_setTexture(global->button_play[i].sprite, global->button_play[i].texture, sfTrue);
        sfSprite_setTextureRect(global->button_play[i].sprite, rect);
        sfSprite_setScale(global->button_play[i].sprite, scale);
        sfSprite_setPosition(global->button_play[i].sprite, pos);
    }
}

void init_button_tuto(global_t *global)
{
    char *path[] = {"buttons/ga_blue.png", "buttons/ga_purple.png"};
    sfVector2f scale = {0.4, 0.4};
    sfIntRect rect = {780, 515, 500, 225};
    sfVector2f pos = {850, 665};
    sfIntRect hitbox = {pos.x, pos.y, 200, 90};
    for (int i = 0; i < 2; i++) {
        global->button_tuto[i].sprite = sfSprite_create();
        global->button_tuto[i].texture = sfTexture_createFromFile(path[i], NULL);
        global->button_tuto[i].rect = hitbox;
        sfSprite_setTexture(global->button_tuto[i].sprite, global->button_tuto[i].texture, sfTrue);
        sfSprite_setTextureRect(global->button_tuto[i].sprite, rect);
        sfSprite_setScale(global->button_tuto[i].sprite, scale);
        sfSprite_setPosition(global->button_tuto[i].sprite, pos);
    }
}

void init_button_quit(global_t *global)
{
    char *path[] = {"buttons/ga_blue.png", "buttons/ga_purple.png"};
    sfVector2f scale = {0.4, 0.4};
    sfIntRect rect = {185, 1125, 500, 225};
    sfVector2f pos = {850, 765};
    sfIntRect hitbox = {pos.x, pos.y, 200, 90};
    for (int i = 0; i < 2; i++) {
        global->button_quit[i].sprite = sfSprite_create();
        global->button_quit[i].texture = sfTexture_createFromFile(path[i], NULL);
        global->button_quit[i].rect = hitbox;
        sfSprite_setTexture(global->button_quit[i].sprite, global->button_quit[i].texture, sfTrue);
        sfSprite_setTextureRect(global->button_quit[i].sprite, rect);
        sfSprite_setScale(global->button_quit[i].sprite, scale);
        sfSprite_setPosition(global->button_quit[i].sprite, pos);
    }
}