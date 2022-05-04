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
    for (; m->map[0].map_txt[l][j] != 'b' ;j++) {
        if (m->map[0].map_txt[l][j+1] == '\0') {
            l++;
            j = 0;
        }
    }
    sfVector2f pose = {l+ 2720,j+1330};
    m->box[0].pos = pose;
    sfSprite_setPosition(m->box[0].sprite,pose);
    return;
}

void moov_box(global_t *m)
{
    sfVector2f poshero = sfSprite_getPosition(m->hero[0].sprite);
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
        printf("%d\n", m->hero[0].check_mouv);
        if (m->hero[0].check_mouv == 4) {
            m->map[0].map_txt[m->hero[0].y+1][m->hero[0].x] = 'x';
            // printf("oui");
        }
        if (m->hero[0].check_mouv == 5) {
            m->map[0].map_txt[m->hero[0].y-1][m->hero[0].x] = 'x';
        }
        if (m->hero[0].check_mouv == 3 || m->hero[0].check_mouv == 7) {
            m->map[0].map_txt[m->hero[0].y][m->hero[0].x+1] = 'x';
        }
        m->map[0].map_txt[m->hero[0].y][m->hero[0].x] = '|';
        m->box[0].take = 0;
        m->box[0].yes = 0;
    }

}

void sokoban(global_t *m)
{
    int i = 0, j = 0;
    sfVector2f poshero = sfSprite_getPosition(m->hero[0].sprite);
    int a = 0, b = 0;
    if (m->map[0].map_txt[m->hero[0].y][m->hero[0].x] == '|') {
       
        sfRenderWindow_drawSprite(m->window, m->toucht[0].sprite, NULL);
        m->box[0].yes = 1;
        // if (sfKeyboard_isKeyPressed((sfMouseButton){sfKeyT})) {
            // m->map[0].map_txt[m->hero[0].y][m->hero[0].x] = '.'; // avant
            //m->box[0].yes = 1;                                   // avant 
        // }
    }
    if (m->map[0].map_txt[m->hero[0].y][m->hero[0].x] == 'r') {
        sfRenderWindow_drawSprite(m->window, m->toucht[0].sprite, NULL);
        m->box[0].yes = 2;
        m->map[0].map_txt[m->hero[0].y][m->hero[0].x+2] = '.';
    }

    if (m->map[0].map_txt[m->hero[0].y][m->hero[0].x] == 'l') {
        sfRenderWindow_drawSprite(m->window, m->toucht[0].sprite, NULL);
        m->box[0].yes = 3;
        m->map[0].map_txt[m->hero[0].y][m->hero[0].x-2] = '.';
    }

    if (m->box[0].yes == 3) {
        if (sfKeyboard_isKeyPressed((sfMouseButton){sfKeyT})) {
            sfVector2f pose = {poshero.x - 60, poshero.y};
            m->box[0].pos = pose;
            sfSprite_setPosition(m->box[0].sprite,pose);
            if (m->hero[0].check_mouv != 6) {
                // printf("iojjf");
                m->map[0].map_txt[m->hero[0].y][m->hero[0].x] = 'l';
                m->map[0].map_txt[m->hero[0].y][m->hero[0].x-2] = 'r';
                m->map[0].map_txt[m->hero[0].y-1][m->hero[0].x-1] = '|';
                m->box[0].yes = 18;
            }
        }
        if (m->eventbox.type == sfEvtKeyReleased && m->event.key.code == sfKeyT) {
            printf("oui");
            m->map[0].map_txt[m->hero[0].y][m->hero[0].x] = 'l';
            m->map[0].map_txt[m->hero[0].y][m->hero[0].x-2] = 'r';
            m->map[0].map_txt[m->hero[0].y-1][m->hero[0].x-1] = '|';
            m->box[0].yes = 18;
        }

    }

    if (m->box[0].yes == 2) {
        if (sfKeyboard_isKeyPressed((sfMouseButton){sfKeyT})) {
            sfVector2f pose = {poshero.x + 60, poshero.y};
            m->box[0].pos = pose;
            sfSprite_setPosition(m->box[0].sprite,pose);
            if (m->hero[0].check_mouv != 7) {
                m->box[0].yes = 18;
            }
        }
        if (m->eventbox.type == sfEvtKeyReleased && m->event.key.code == sfKeyT)
            m->box[0].yes = 18;
    }

    if (m->box[0].yes == 1) {
        if (sfKeyboard_isKeyPressed((sfMouseButton){sfKeyT})) {
            m->map[0].map_txt[m->hero[0].y][m->hero[0].x] = '.';
            m->map[0].map_txt[m->hero[0].y-1][m->hero[0].x+1] = '.';
            m->map[0].map_txt[m->hero[0].y-1][m->hero[0].x-1] = '.';
        // moov_box(m);
            sfVector2f pose = {poshero.x, poshero.y + 35};
            m->box[0].pos = pose;
            sfSprite_setPosition(m->box[0].sprite,pose);
            if (m->hero[0].check_mouv != 4) {
                m->box[0].yes = 18;
            }
        }
        if (m->eventbox.type == sfEvtKeyReleased && m->event.key.code == sfKeyT)
            m->box[0].yes = 18;
    }
        // if (m->hero[0].check_mouv == 4) {
        //     printf("%d\n", m->box[0].yes);
        //     sfVector2f pose = {poshero.x, poshero.y + 35};
        //     m->box[0].pos = pose;
        //     sfSprite_setPosition(m->box[0].sprite,pose);
        //     m->box[0].take = 1;
        // }
    // }
    sfRenderWindow_drawSprite(m->window, m->box[0].sprite, NULL);
}