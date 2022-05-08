/*
** EPITECH PROJECT, 2021
** draw_poster.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_box(global_t *m)
{
    m->box[0].yes = 0;
    m->box[0].take = 0;
    m->facty = 0;
    int l = 0;
    int j = 0;
    sfIntRect rect = {0, 0, 300, 45};
    m->box[0].sprite = make_sprite("sprite/box/box.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_setScale(m->box[i].sprite, (sfVector2f){1.5, 1.5});
    }
    for (; m->map[1].map_txt[l][j] != 'b' ;j++) {
        if (m->map[1].map_txt[l][j+1] == '\0') {
            l++;
            j = 0;
        }
    }
    sfVector2f pose = {l+ 4850,j+2450};
    m->box[0].pos = pose;
    sfSprite_setPosition(m->box[0].sprite,pose);
    return;
}

void moov_box(global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->light[0].sprite, NULL);
    sfVector2f poshero = sfSprite_getPosition(m->hero[1].sprite);
    sfMouseButton put = sfKeyP;
    if (m->hero[0].check_mouv == 4) {
        sfVector2f pose = {poshero.x, poshero.y + 35};
        m->box[0].pos = pose;
        sfSprite_setPosition(m->box[0].sprite,pose);
        m->box[0].take = 1;
    }
    if (m->hero[0].check_mouv == 6) {
        sfVector2f pose = {poshero.x - 60, poshero.y};
        m->box[0].pos = pose;
        sfSprite_setPosition(m->box[0].sprite,pose);
        m->box[0].take = 2;
    }
    if (m->hero[0].check_mouv == 7) {
        sfVector2f pose = {poshero.x + 60, poshero.y};
        m->box[0].pos = pose;
        sfSprite_setPosition(m->box[0].sprite,pose);
        m->box[0].take = 3;
    }
    if (m->hero[0].check_mouv == 5) {
        sfVector2f pose = {poshero.x, poshero.y - 26};
        m->box[0].pos = pose;
        sfSprite_setPosition(m->box[0].sprite,pose);
        m->box[0].take = 4;
    }
    if (sfKeyboard_isKeyPressed(put)) {
        if (m->map[1].map_txt[m->hero[1].y][m->hero[1].x] == 'q') {
            m->box[0].take = 0;
            m->box[0].yes = 8;
            m->map[1].map_txt[32][47] = '.';
            m->map[1].map_txt[32][48] = '.';
            m->map[1].map_txt[32][49] = '.';
        } else {
            m->map[1].map_txt[m->hero[1].y][m->hero[1].x] = '|';
            m->box[0].take = 0;
            m->box[0].yes = 0;
        }
    }
}

void sokoban(global_t *m)
{
    sfMouseButton space = sfKeySpace;
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    if (m->map[1].map_txt[m->hero[1].y][m->hero[1].x] == '|') {
        sfRenderWindow_drawSprite(m->window, m->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space)) {
            m->map[1].map_txt[m->hero[1].y][m->hero[0].x] = '.';
            m->box[0].yes = 1;
        }
    }
    if (m->box[0].yes == 1) moov_box(m);
        sfSprite_setPosition(m->box[0].sprite, m->box[0].pos);
    sfRenderWindow_drawSprite(m->window, m->box[0].sprite, NULL);
    if (m->box[0].yes != 8) {
        sfSprite_setPosition(m->labydoor[0].sprite,m->labydoor[0].pos);
        sfRenderWindow_drawSprite(m->window, m->labydoor[0].sprite, NULL);
    }
    if (m->box[0].yes == 8)
        anim_labydoor(m);
}
