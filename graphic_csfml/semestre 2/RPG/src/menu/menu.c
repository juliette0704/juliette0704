/*
** EPITECH PROJECT, 2021
** menu.c
** File description:
** my_defender
*/

#include "my_rpg.h"

void init_avatar(global_t *m)
{
    sfIntRect rect = {2, 0, 48, 48};
    m->avatar->yes = 0;
    m->avatar[0].rect = rect;
    sfVector2f pos = {850,300};
    m->avatar[0].sprite = make_sprite("avatar.png");
    for (int i = 0; i < 1; i++)
        sfSprite_setPosition(m->avatar[i].sprite, pos);
    return;
}

void choose_avatar(global_t *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
    static int x = 100;
    static int y = 200;
    static int j = 0;
    static int l = 0;
    static int choose = 0;
    sfIntRect rect = {j, l, x, y};
    if (m->event.type == sfEvtMouseButtonReleased) // et pose des bouttons de la souris
        m->avatar->yes = 1;
    if (m->avatar->yes == 1) {
        choose++;
        if (j >= 400) {
            j = 0;
            choose = 0;
        } else j += 120;
        m->event.type = sfEvtKeyPressed;
        m->avatar->yes = 0;
    }
    sfSprite_setTextureRect(m->avatar[0].sprite, rect);
    sfRenderWindow_drawSprite(m->window, m->avatar[0].sprite, NULL);
}