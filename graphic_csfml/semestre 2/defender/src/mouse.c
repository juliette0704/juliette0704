/*
** EPITECH PROJECT, 2022
** mouse
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

void mouse_tower(global_t *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
    sfMouseButton bout = sfMouseLeft;
    if (sfMouse_isButtonPressed(bout)) {
        if (pos.x > 1767 && pos.x < 1863 && pos.y > 981 && pos.y < 1052)
            sfRenderWindow_close(m->window);
    }
}

void mouse_tower1_select(global_t *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
    // sfVector2f post = {pos.x, pos.y};
    sfVector2f first = {185, 460};
    sfVector2f second = {855, 590};
    sfMouseButton bout = sfMouseLeft;
    if (sfMouse_isButtonPressed(bout)) {
        if (pos.x > 1748 && pos.x < 1796 && pos.y > 533 && pos.y < 599) {
            if (m->score_bit >= 10) {
                printf("oui");
                m->dispmoney = 1;
                m->z = 1;
                m->score_bit -= 9;
            } else if (m->dispmoney == 0) {
                sfRenderWindow_drawText(m->window, m->textmoney, NULL);
            }
        }
    }
    if (m->z == 1) {
        if (m->firstplace == 1) {
            printf("t1");
            m->ist1 = 1;
            sfSprite_setPosition(m->tower2->s_t2[0],(sfVector2f){-200,-200});
            m->tower1 = (sfIntRect){200, 0, 100, 300};
            sfSprite_setTextureRect(m->towere1->s_t1[0], m->tower1);
            sfSprite_setPosition(m->towere1->s_t1[0], first);
            m->firstplace = 0;
            sfSprite_setPosition(m->place->s_place[0], (sfVector2f){-200,-200});
        }
        if (m->secondplace == 1) {
            m->ist2 = 1;
            sfSprite_setPosition(m->tower2->s_t2[1],(sfVector2f){-200,-200});
            m->tower1 = (sfIntRect){200, 0, 100, 300};
            sfSprite_setTextureRect(m->towere1->s_t1[1], m->tower1);
            sfSprite_setPosition(m->towere1->s_t1[1], second);
            m->secondplace = 0;
            sfSprite_setPosition(m->place->s_place[1], (sfVector2f){-200,-200});
        }
    }
    m->z = 0;
    sfRenderWindow_drawSprite(m->window, m->towere1->s_t1[0], NULL);
    sfRenderWindow_drawSprite(m->window, m->towere1->s_t1[1], NULL);
}

void mouse_tower2_select(global_t *m)
{
        sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
        // sfVector2f post = {pos.x, pos.y};
        sfVector2f first = {185, 460};
        sfVector2f second = {855, 590};
        sfMouseButton bout = sfMouseLeft;
        if (sfMouse_isButtonPressed(bout)) {
            if (pos.x > 1712 && pos.x < 1771 && pos.y > 658 && pos.y < 724) {
                if (m->score_bit > 19) {
                    m->dispmoney = 1;
                    m->score_bit -= 19;
                    m->z = 1;
                    // m->ist2 = 1;
                } else if (m->dispmoney == 0 ) {
                    sfRenderWindow_drawText(m->window, m->textmoney, NULL);
                }
            }
        }
        if (m->z == 1) {
            if (m->firstplace == 1) {
                m->toucht2 = 1;
                sfSprite_setPosition(m->towere1->s_t1[0],(sfVector2f){-200,-200});
                m->rectower2 = (sfIntRect){200, 0, 100, 300};
                sfSprite_setTextureRect(m->tower2->s_t2[0], m->rectower2);
                sfSprite_setPosition(m->tower2->s_t2[0], first);
                m->firstplace = 0;
                sfSprite_setPosition(m->place->s_place[0], (sfVector2f){-200,-200});
            }
            if (m->secondplace == 1) {
                m->toucht3 = 1;
                sfSprite_setPosition(m->towere1->s_t1[1],(sfVector2f){-200,-200});
                m->rectower2 = (sfIntRect){200, 0, 100, 300};
                sfSprite_setTextureRect(m->tower2->s_t2[1], m->rectower2);
                sfSprite_setPosition(m->tower2->s_t2[1], second);
                m->secondplace = 0;
                sfSprite_setPosition(m->place->s_place[1], (sfVector2f){-200,-200});
            }
        }
        m->z = 0;
        sfRenderWindow_drawSprite(m->window, m->tower2->s_t2[0], NULL);
        sfRenderWindow_drawSprite(m->window, m->tower2->s_t2[1], NULL);
}

void mouse_tower3_select(global_t *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
    // sfVector2f post = {pos.x, pos.y};
    sfVector2f first = {185, 460};
    sfVector2f second = {855, 590};
    sfMouseButton bout = sfMouseLeft;
    if (sfMouse_isButtonPressed(bout)) {
        if (pos.x > 1742 && pos.x < 1796 && pos.y > 789 && pos.y < 876) {
            if (m->score_bit >= 30) {
                m->z = 1;
                m->dispmoney = 1;
                m->score_bit -= 30;
            } else if (m->dispmoney == 0 ) {
                    sfRenderWindow_drawText(m->window, m->textmoney, NULL);
            }
        }
    }
    if (m->z == 1) {
        if (m->firstplace == 1) {
            sfSprite_setPosition(m->tower2->s_t2[0],(sfVector2f){-200,-200});
            sfSprite_setPosition(m->towere1->s_t1[0],(sfVector2f){-200,-200});
            m->rectower3 = (sfIntRect){200, 0, 100, 300};
            sfSprite_setTextureRect(m->tower3->s_t3[0], m->rectower3);
            sfSprite_setPosition(m->tower3->s_t3[0], first);
            m->firstplace = 0;
            sfSprite_setPosition(m->place->s_place[0], (sfVector2f){-200,-200});
        }
        if (m->secondplace == 1) {
            sfSprite_setPosition(m->tower2->s_t2[1],(sfVector2f){-200,-200});
            sfSprite_setPosition(m->towere1->s_t1[1],(sfVector2f){-200,-200});
            m->rectower3 = (sfIntRect){200, 0, 100, 300};
            sfSprite_setTextureRect(m->tower3->s_t3[1], m->rectower3);
            sfSprite_setPosition(m->tower3->s_t3[1], second);
            m->secondplace = 0;
            sfSprite_setPosition(m->place->s_place[1], (sfVector2f){-200,-200});
        }
    }
    m->z = 0;
    sfRenderWindow_drawSprite(m->window, m->tower3->s_t3[0], NULL);
    sfRenderWindow_drawSprite(m->window, m->tower3->s_t3[1], NULL);
}