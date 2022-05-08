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
        end_game(global);
    if (global->event.type == sfEvtKeyPressed) {
        if (global->event.key.code == sfKeyA && global->hero[0].check_attack == 0) {
            if (global->inventory[0].gold_i > 0) {
                global->attack = 1;
                global->hero[0].check_attack = 1;
                global->hero[0].rect_attack.left = 0;
            }
        }
        if (global->event.key.code == sfKeyZ && global->shield[0].active == 0) {
            if (global->shield[0].cd == 0) {
                global->shield[0].active = 1;
                global->shield[0].cd = 1;
            }
            if (global->shield[0].sec_cd > 10) {
                global->shield[0].cd = 0;
                sfClock_restart(global->shield[0].clock_cd);
            }
        }
    }
    if (global->scene == -4)
        menu_button_selected(global);
    return;
}

int start_game(global_t *global)
{
    sfRenderWindow_setFramerateLimit(global->window, 60);
    while (sfRenderWindow_isOpen(global->window)) {
        global->shield[0].sec_cd = make_clock(global->shield[0].clock_cd);
        sfVector2i mousepos = sfMouse_getPositionRenderWindow(global->window);
        sfVector2f mousepos_cursor = {mousepos.x, mousepos.y};
        global->mouse = mousepos_cursor;
        sfSprite_setPosition(global->cursor.sprite, mousepos_cursor);
        while (sfRenderWindow_pollEvent(global->window, &global->event)) {
            quit_start_game(global->window, global);
        }
        if (global->my_exit == 1)
            return 1;
        for (int i = 0; i < 5; i++) {
            sfSprite_setPosition(global->hero[i].sprite, global->hero[0].pos);
        }
        global->cursor.sec = make_clock(global->cursor.clock);
        global->hero[0].sec = make_clock(global->hero[0].clock);
        global->intro[0].sec = make_clock(global->intro[0].clock);
        global->hero[1].sec = make_clock(global->hero[1].clock);
        global->png_crest[0].sec = make_clock(global->png_crest[0].clock);
        for (int i = 0; i < global->nb_slime; i++)
            global->enemy[i].sec = make_clock(global->enemy[i].clock);
        global->rain[0].sec = make_clock(global->rain[0].clock);
        global->speaker[0].sec = make_clock(global->speaker[0].clock);
        global->fire[0].sec = make_clock(global->fire[0].clock);
        global->shield[0].sec = make_clock(global->shield[0].clock);
        global->boss.sec = make_clock(global->boss.clock);
        global->fire[0].sec_f = make_clock(global->fire[0].clock_f);
        global->labydoor[0].sec = make_clock(global->labydoor[0].clock);
        global->mentor[0].sec = make_clock(global->mentor[0].clock);
        global->bubble[0].sec = make_clock(global->bubble[0].clock);
        global->sec_bird = make_clock(global->clock_bird);
        global->sec_menu = make_clock(global->clock_menu);
        global->labydoor[1].sec = make_clock(global->labydoor[1].clock);
        global->particle[0].sec = make_clock(global->particle[0].clock);
        // global->quest[0].sec = make_clock(global->quest[0].clock);
        sfRenderWindow_clear(global->window, sfBlack);
        switch (global->scene) {
            case -5 :
                game_over_final(global);
                break;
            case -4 :
                draw_menu(global->window, global);
                break;
            case -3 :
                if (draw_pause(global) == 1)
                    return 1;
                break;
            case -2 :
                draw_game_over(global);
                break;
            case -1 :
                draw_intro(global);
                break;
            case 0 :
                start_map(global->window, global);
                break;
            case 1 :
                draw_house(global->window, global, 0);
                break;
            case 2 :
                draw_house(global->window, global, 1);
                break;
            case 3 :
                draw_dungeon(global);
                break;
            case 4 :
                draw_island(global);
                break;
            case 5 :
                draw_arena(global);
                break;
            case 6 :
                draw_final(global);
                break;
            case 7 :
                draw_end_game(global);
                break;
            default :
                break;
        }
        if (global->scene >= 0 && global->scene < 7) {
            draw_inventory(global);
            sfMouseButton echap = sfKeyEscape;
            if (sfKeyboard_isKeyPressed(echap)) {
                global->scene_past = global->scene;
                global->scene = -3;
            }
            draw_life(global);
            sfMouseButton pot_2 = sfKeyNum2;
            if (sfKeyboard_isKeyPressed(pot_2) && global->potion[0].is_pot == 1) {
                global->life[0].life = 0;
                global->potion[0].is_pot = 0;
            }
            sfMouseButton pot_1 = sfKeyNum1;
            if (sfKeyboard_isKeyPressed(pot_1) && global->potion[1].is_pot == 1) {
                if (global->life[0].life > 0)
                    global->life[0].life--;
                global->potion[1].is_pot = 0;
            }
        }
        cursor_animation(global);
        sfRenderWindow_display(global->window);
    }
    return 0;
}
