/*
** EPITECH PROJECT, 2022
** sprite_bit.c
** File description:
** phone
*/

#include "my.h"
#include "defender.h"
#include <math.h>

bit_t *sprite_bit(global_t *t)
{
    int j = 0;
    bit_t *m = malloc(sizeof(bit_t));
    char *file[] = {"./menu/bitcoin.png"};
    m->file = file;
    m->s_bit[0] = sfSprite_create();
    m->t_bit[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(m->s_bit[0], m->t_bit[0], sfTrue);
    sfSprite_setPosition(m->s_bit[0], (sfVector2f){50, 50});
    return m;
}

rect_t *sprite_rect(global_t *t)
{
    int j = 0;
    rect_t *m = malloc(sizeof(rect_t));
    char *file[] = {"./menu/rectangle.png"
    , "./menu/rectangle.png"};
    m->file = file;
    int x = 0;
    for (int i = 0; i <= 1; i++) {
        m->s_rect[i] = sfSprite_create();
        m->t_rect[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_rect[i], m->t_rect[j], sfTrue);
        sfSprite_setPosition(m->s_rect[0], (sfVector2f){180, 350});
        sfSprite_setPosition(m->s_rect[1], (sfVector2f){800, 550});

        j++;
    }
    return m;
}

void zone_sprite_touch(global_t *m)
{
    sfVector2f pos_en1 = sfSprite_getPosition(m->ennemi->s_enemis[0]);
    sfVector2f pos_en2 = sfSprite_getPosition(m->ennemi->s_enemis[1]);

    sfIntRect spacemente = (sfIntRect){0 , 0,300, 300};
    sfIntRect spacemente2 = (sfIntRect){180 ,350,300, 300};
    sfIntRect spacement = (sfIntRect){0, 0, 300, 300};
    sfIntRect spacement2 = (sfIntRect){800 ,550,300, 350};

    m->timerect = sfClock_getElapsedTime(m->clockrect);
    m->secondrect = m->timerect.microseconds / 1000000.0;
    if (pos_en1.x == -250) {
        m->life_en1 += 3;
        m->level++;
        m->dispmoney = 0;
        sfSprite_setPosition(m->ennemi->s_enemis[0], (sfVector2f){-249, pos_en1.y});
    }
    //////////////////
    if (m->ist1 == 1) {
        if (sfIntRect_contains(&spacemente2, pos_en1.x, pos_en1.y) && m->secondrect > 0.5) {
            m->lify = 1;
            sfClock_restart(m->clockrect);
        }
        if (m->lify == 1) {
            m->life_en1 -= 1;
            if (m->life_en1 <= 0) {
                sfSprite_setPosition(m->ennemi->s_enemis[0], (sfVector2f){-500, -500});
                m->score_bit += 15;
                m->life_en1 = m->level * 5 + 3;
            }
            m->lify = 0;
        }
    }
    ////////////////////
    // if (m->ist1 == 1) {
    //     if (sfIntRect_contains(&spacemente2, pos_en2.x, pos_en2.y) && m->secondrect > 0.5) {
    //         m->tkt = 1;
    //         sfClock_restart(m->clockrect);
    //     }
    //     if (m->tkt == 1) {
    //         m->life_en2 -= 1;
    //         if (m->life_en2 <= 0) {
    //             sfSprite_setPosition(m->ennemi->s_enemis[1], (sfVector2f){-500, -500});
    //             m->score_bit += 15;
    //             m->life_en2 = m->level * 5 + 3;
    //         }
    //         m->tkt = 0;
    //     }
    // }
    ////////////////////
    if (m->ist2 == 1) {
        if (sfIntRect_contains(&spacement2, pos_en1.x, pos_en1.y) && m->secondrect > 0.5) {
            m->life_en1 -= 1;
            if (m->life_en1 == 0) {
                sfSprite_setPosition(m->ennemi->s_enemis[0], (sfVector2f){-500, -500});
                m->score_bit += 15;
                m->life_en1 = m->level * 5 + 3;
            }
            m->lify = 0;
            sfClock_restart(m->clockrect);
        }
    }
    /////////////////////
    if (m->toucht2 == 1) {
        if (sfIntRect_contains(&spacemente2, pos_en1.x, pos_en1.y) && m->secondrect > 0.5) {
            m->lify = 1;
            sfClock_restart(m->clockrect);
        }
        if (m->lify == 1) {
            m->life_en1 -= 2;
            if (m->life_en1 <= 0) {
                sfSprite_setPosition(m->ennemi->s_enemis[0], (sfVector2f){-500, -500});
                m->score_bit += 15;
                m->life_en1 = m->level * 5 + 6;
            }
            m->lify = 0;
        }
    }
    ////////////////////
    if (m->toucht3 == 1) {
        if (sfIntRect_contains(&spacement2, pos_en1.x, pos_en1.y) && m->secondrect > 0.5) {
            m->lify = 1;
            sfClock_restart(m->clockrect);
        }
        if (m->lify == 1) {
            m->life_en1 -= 2;
            if (m->life_en1 <= 0) {
                sfSprite_setPosition(m->ennemi->s_enemis[0], (sfVector2f){-500, -500});
                m->score_bit += 15;
                m->life_en1 = m->level * 5 + 6;
            }
            m->lify = 0;
        }
    }

}