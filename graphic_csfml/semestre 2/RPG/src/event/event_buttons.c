/*
** EPITECH PROJECT, 2022
** Menu
** File description:
** event_buttons
*/

#include "my_rpg.h"

void menu_button_clicked(global_t *global)
{
    if (global->event.type == sfEvtMouseButtonReleased && global->event.mouseButton.button == sfMouseLeft) {
        switch (global->apt) {
        case 1:
            global->scene = -1;
            break;
        case 2:
            global->scene = 4;
            break;
        case 3:
            end_game(global);
            break;
        default:
            break;
        }
    }
    return;
}

void menu_button_selected(global_t *global)
{
    if (sfIntRect_contains(&global->button_play[0].rect, global->mouse.x, global->mouse.y))
        global->apt = 1;
    else if (sfIntRect_contains(&global->button_tuto[0].rect, global->mouse.x, global->mouse.y))
        global->apt = 2;
    else if (sfIntRect_contains(&global->button_quit[0].rect, global->mouse.x, global->mouse.y))
        global->apt = 3;
    else
        global->apt = 0;
    menu_button_clicked(global);
    return;
}