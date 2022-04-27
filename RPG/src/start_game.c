/*
** EPITECH PROJECT, 2021
** start_game
** File description:
** my_hunter
*/

#include "my_rpg.h"

void quit_start_game(sfRenderWindow *window, global_t *global)
{
    if (global->event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (global->event.type == sfEvtKeyReleased)
        if (global->event.key.code == sfKeyA && global->hero[0].check_attack == 0) {
            global->hero[0].check_attack = 1;
            global->hero[0].rect_attack.left = 0;
        }
    return;
}

int start_game(global_t *global)
{
    sfRenderWindow_setFramerateLimit(global->window, 60);
    while (sfRenderWindow_isOpen(global->window)) {
        sfVector2i mousepos = sfMouse_getPositionRenderWindow(global->window);
        sfVector2f mousepos_cursor = {mousepos.x, mousepos.y};
        sfSprite_setPosition(global->cursor.sprite, mousepos_cursor);
        for (int i = 0; i < 5; i++) {
            sfSprite_setPosition(global->hero[i].sprite, global->hero[0].pos);
        }
        global->cursor.sec = make_clock(global->cursor.clock);
        global->hero[0].sec = make_clock(global->hero[0].clock);
        global->hero[1].sec = make_clock(global->hero[1].clock);
        global->png_crest[0].sec = make_clock(global->png_crest[0].clock);
        global->enemy[0].sec = make_clock(global->enemy[0].clock);
        global->rain[0].sec = make_clock(global->rain[0].clock);
        global->speaker[0].sec = make_clock(global->speaker[0].clock);
        global->fire[0].sec = make_clock(global->speaker[0].clock);
        sfRenderWindow_clear(global->window, sfBlack);
        while (sfRenderWindow_pollEvent(global->window, &global->event)) {
            quit_start_game(global->window, global);
        }
        switch (global->scene) {
            case 0 :
                start_map(global->window, global);
                break;
            case 1 :
                draw_house(global->window, global, 0);
                break;
            case 2 :
                draw_house(global->window, global, 1);
            default :
                break;
        }
    }
    return 0;
}
