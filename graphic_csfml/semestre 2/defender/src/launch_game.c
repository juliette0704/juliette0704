/*
** EPITECH PROJECT, 2022
** launch_game
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

void play(global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->bg->s_bg[0], NULL);
    print_place(m);
    emplace_tower(m);
    if (m->event.type == sfEvtMouseButtonPressed && m->j == 1)
        m->j = 0;
    if (m->j == 1)
        display_menu_tower(m);
    if (key_pause(m) == 1) {
        test :
        m->a = 1;
        pause_main(m);
    }
    else {
        if (m->event.type == sfEvtMouseMoved && m->a == 1)
            goto test;
        m->a = 0;
        ennemi_wave(m);
    }
}

void game_loop(global_t *m)
{
    while (sfRenderWindow_isOpen(m->window)) {
        sfRenderWindow_clear(m->window, sfBlack);
        while (sfRenderWindow_pollEvent(m->window, &m->event)) {
            if (m->event.type == sfEvtClosed)
                sfRenderWindow_close(m->window);
        }
        if (m->menu == 1) {
            play(m);
        }
        else {
            mouse_menu(m);
            menu(m);
        }
        sfRenderWindow_display(m->window);
    }
}
