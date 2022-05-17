/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** draw
*/

#include "my_rpg.h"

void draw_menu(sfRenderWindow *window, global_t *global)
{
    draw_landscape(window, global);
    bird_draw(window, global);
    button_draw(window, global);
    change_position(global);
    condition(global);
    return;
}

void draw_landscape(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->font_blue.sprite, sfFalse);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, global->big_cloud[i].sprite, sfFalse);
    sfRenderWindow_drawSprite(window, global->behind_cloud.sprite, sfFalse);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, global->mountains[i].sprite, sfFalse);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, global->fine_cloud[i].sprite, sfFalse);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, global->multiple_clouds[i].sprite, sfFalse);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawSprite(window, global->front_clouds[i].sprite, sfFalse);
    return;
}

void button_draw(sfRenderWindow *window, global_t *global)
{
    sfRenderWindow_drawSprite(window, global->button_play[0].sprite, sfFalse);
    sfRenderWindow_drawSprite(window, global->button_quit[0].sprite, sfFalse);
    sfRenderWindow_drawSprite(window, global->button_tuto[0].sprite, sfFalse);
    sfRenderWindow_drawSprite(window, global->title.sprite, sfFalse);
    return;
}

void bird_draw(sfRenderWindow *window, global_t *global)
{
    for (int i = 0; i < 10; i++)
        sfRenderWindow_drawSprite(window, global->bird[i].sprite, sfFalse);
    return;
}