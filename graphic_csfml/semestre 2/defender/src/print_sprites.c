/*
** EPITECH PROJECT, 2022
** print_sprites
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

void print_tower(global_t *m)
{
    for (int i = 0; i <= 3; i++)
        sfRenderWindow_drawSprite(m->window, m->tower->s_bui[i], NULL);
}

void print_place(global_t *m)
{

    sfRenderWindow_drawSprite(m->window, m->bit->s_bit[0], NULL);
    sfRenderWindow_drawSprite(m->window, m->place->s_place[0], NULL);
    sfRenderWindow_drawSprite(m->window, m->place->s_place[1], NULL);
}

void print_sprite2(global_t *m)
{
    m->timeskin2 = sfClock_getElapsedTime(m->clockskin2);
    m->secondskin2 = m->timeskin2.microseconds / 1000000.0;
        if (m->secondskin2 > 0.09) {
            init_rect_sprite2(m);
            sfClock_restart(m->clockskin2);
            if (m->speed2 >= 990) {
                m->speed2 = 209;
            }
            else
                m->speed2 += 209;
        }
    m->timemoov2 = sfClock_getElapsedTime(m->clockmoov2);
    m->secondmoov2 = m->timemoov2.microseconds / 1000000.0;
    if (m->secondmoov2 > 0.09) {
        moov_ennemis2(m);
    }
    sfRenderWindow_drawSprite(m->window, m->ennemi->s_enemis[1], NULL);
}

void print_sprite1(global_t *m)
{
    m->timeskin = sfClock_getElapsedTime(m->clockskin);
    m->secondskin = m->timeskin.microseconds / 1000000.0;
        if (m->secondskin > 0.09) {
            init_rect_sprite1(m);
            sfClock_restart(m->clockskin);
            if (m->speed >= 2075) {
                m->speed = 225;
            }
            else
                m->speed += 225;
        }
    m->timemoov = sfClock_getElapsedTime(m->clockmoov);
    m->secondmoov = m->timemoov.microseconds / 1000000.0;
    if (m->secondmoov > 0.09) {
        moov_ennemis(m);
    }
    sfRenderWindow_drawSprite(m->window, m->ennemi->s_enemis[0], NULL);

}
