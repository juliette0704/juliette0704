/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** condition
*/

#include "my_rpg.h"

void condition(global_t *global)
{
    if (global->apt == 1)
        play_draw(global->window, global);
    if (global->apt == 2)
        tuto_draw(global->window, global);
    if (global->apt == 3)
        quit_draw(global->window, global);
}