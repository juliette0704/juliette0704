/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** init
*/

#include "my_rpg.h"

void init_buttons(global_t *global)
{
    init_button_play(global);
    init_button_quit(global);
    init_button_tuto(global);
}

void create_clock(global_t *global)
{
    float sec;
    sfClock *clock;
    global->sec_menu = sec;
    global->clock_menu = clock;
    global->clock_menu = sfClock_create();
    global->sec_bird = sec;
    global->clock_bird = clock;
    global->clock_bird = sfClock_create();
}

void init_menu(global_t *global)
{
    create_clock(global);
    init_title(global);
    init_mountains(global);
    init_background(global);
    init_big_clouds(global);
    init_fine_clouds(global);
    init_front_clouds(global);
    init_behind_clouds(global);
    init_multiple_clouds(global);
}

void init(global_t *global)
{
    init_menu(global);
    init_birds(global);
    init_buttons(global);
}