/*
** EPITECH PROJECT, 2022
** waves
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

void send_waves(global_t *m)
{
    // print_place(m);
    if (m->life_game == 0)
        sfRenderWindow_close(m->window);
    mouse_tower(m);
    print_sprite1(m);
    print_sprite2(m);
    zone_sprite_touch(m);
}

void ennemi_wave(global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->minis1->s_minis1[0], NULL);
    init_money(m);
    init_score(m);
    init_heart(m);
    init_minitext(m);
    sfRenderWindow_drawText(m->window, m->textmini1, NULL);
    sfRenderWindow_drawText(m->window, m->textheart, NULL);
    sfRenderWindow_drawText(m->window, m->text, NULL);
    sfRenderWindow_drawSprite(m->window, m->heart->s_heart[0], NULL);
    m->timennemi = sfClock_getElapsedTime(m->clockennemi);
    m->secondennemi = m->timennemi.microseconds / 1000000.0;
    sfVector2f pos = sfSprite_getPosition(m->ennemi->s_enemis[0]);
    if (m->secondennemi > 5.09) {
            send_waves(m);
    }
}
