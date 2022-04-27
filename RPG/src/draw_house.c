/*
** EPITECH PROJECT, 2022
** draw_house
** File description:
** my_rpg
*/

#include "my_rpg.h"

void deplace_up_h(global_t *global, int i)
{
    global->house[i].my_view.top -= 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 5;
    global->house[i].up += 1;
    return;
}

void deplace_left_h(global_t *global, int i)
{
    global->house[i].my_view.left -= 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 6;
    global->house[i].left += 1;
    return;
}

void deplace_down_h(global_t *global, int i)
{
    global->house[i].my_view.top += 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 4;
    global->house[i].down += 1;
    return;
}

void deplace_right_h(global_t *global, int i)
{
    global->house[i].my_view.left += 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 7;
    global->house[i].right += 1;
    return;
}

void deplace_in_house(sfRenderWindow *window, global_t *global, int i)
{
    // sfSprite_setPosition(global->map[0].back, global->map[0].pos_front);
    // sfSprite_setPosition(global->map[0].front, global->map[0].pos_front);
    global->hero[0].check_mouv = global->hero[0].check_idle;
    sfMouseButton down = sfKeyDown;
    if (sfKeyboard_isKeyPressed(down) && global->house[i].my_view.top < 1380) {
        if (global->house[i].house_txt[global->house[i].y + 1][global->house[i].x] != 'x')
            deplace_down_h(global, i);
    }
    sfMouseButton up = sfKeyUp;
    if (sfKeyboard_isKeyPressed(up) && global->house[i].my_view.top > 0) {
        if (global->house[i].house_txt[global->house[i].y - 1][global->house[i].x] != 'x')
            deplace_up_h(global, i);
    }
    sfMouseButton left = sfKeyLeft;
    if (sfKeyboard_isKeyPressed(left) && global->house[i].my_view.left > 0) {
        if (global->house[i].house_txt[global->house[i].y][global->house[i].x - 1] != 'x')
            deplace_left_h(global, i);
    }
    sfMouseButton right = sfKeyRight;
    if (sfKeyboard_isKeyPressed(right) && global->house[i].my_view.left < 2420) {
        if (global->house[i].house_txt[global->house[i].y][global->house[i].x + 1] != 'x')
            deplace_right_h(global, i);
    }
    if (global->house[i].down > 11) {
        global->house[i].y++;
        global->house[i].down = 0;
    }
    if (global->house[i].up > 11) {
        global->house[i].y--;
        global->house[i].up = 0;
    }
    if (global->house[i].left > 11) {
        global->house[i].x--;
        global->house[i].left = 0;
    }
    if (global->house[i].right > 11) {
        global->house[i].x++;
        global->house[i].right = 0;
    }
    if (global->hero[0].check_mouv >= 0 && global->hero[0].check_mouv < 4)
        move(window, global, global->hero[0].check_idle);
    else if (global->hero[0].check_mouv >= 4 && global->hero[0].check_mouv < 8) {
        global->hero[0].check_idle = global->hero[0].check_mouv - 4;
        global->hero[0].speed = 1;
        move(window, global, global->hero[0].check_mouv);
    }
    //sfSprite_setPosition(global->map[0].back, global->map[0].pos_front);
    //sfSprite_setPosition(global->map[0].front, global->map[0].pos_front);
    return;
}

void go_out_house(sfRenderWindow *window, global_t *global, int i)
{
    sfMouseButton enter = sfKeyEnter;
    if (global->house[i].house_txt[global->house[i].y][global->house[i].x] == 'o') {
        sfRenderWindow_drawSprite(window, global->house[0].enter, NULL);
        if (sfKeyboard_isKeyPressed(enter)) {
            global->house[i].is_open = 0;
            global->scene = 0;
        }
    }
    return;
}

void draw_house(sfRenderWindow *window, global_t *global, int i)
{
    deplace_in_house(global->window, global, i);
    talk_to_png(global, window);
    sfSprite_setTextureRect(global->house[i].sprite, global->house[i].my_view);
    sfRenderWindow_drawSprite(window, global->house[i].sprite, NULL);
    sfRenderWindow_drawSprite(window, global->hero[global->hero[0].check_mouv].sprite, NULL);
    go_out_house(window, global, i);
    sfRenderWindow_display(window);
    return;
}
