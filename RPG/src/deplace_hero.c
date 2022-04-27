/*
** EPITECH PROJECT, 2022
** deplace_hero
** File description:
** my_rpg
*/

#include "my_rpg.h"

void deplace_down(global_t *global)
{
    global->map[0].my_view.top += 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 4;
    global->hero[0].down += 1 * global->hero[0].speed;
    global->map[0].pos_front.y -= 4 * global->hero[0].speed;
    global->png_crest[0].pos.y -= 4 * global->hero[0].speed;
    global->enemy[0].pos.y -= 4 * global->hero[0].speed;
    global->speak[0].pos_button.y -= 4 * global->hero[0].speed;
    for (int i = 0; i < 2; i++) {
        global->door[i].pos.y -= 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[0].sprite, global->door[i].pos);
    }
    for (int i = 0; global->map[0].map_txt[i] != NULL; i++) {
        global->map[i].pos.y -= 4 * global->hero[0].speed;
        sfText_setPosition(global->map[i].temp, global->map[i].pos);
    }
    return;
}

void deplace_up(global_t *global)
{
    global->map[0].my_view.top -= 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 5;
    global->hero[0].up += 1 * global->hero[0].speed;
    global->png_crest[0].pos.y += 4 * global->hero[0].speed;
    global->enemy[0].pos.y += 4 * global->hero[0].speed;
    global->speak[0].pos_button.y += 4 * global->hero[0].speed;
    global->map[0].pos_front.y += 4 * global->hero[0].speed;
    for (int i = 0; i < 2; i++) {
        global->door[i].pos.y += 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[0].sprite, global->door[i].pos);
    }
    for (int i = 0; global->map[0].map_txt[i] != NULL; i++) {
        global->map[i].pos.y += 4 * global->hero[0].speed;
        sfText_setPosition(global->map[i].temp, global->map[i].pos);
    }
    return;
}

void deplace_left(global_t *global)
{
    global->map[0].my_view.left -= 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 6;
    global->hero[0].left += 1 * global->hero[0].speed;
    global->png_crest[0].pos.x += 4 * global->hero[0].speed;
    global->enemy[0].pos.x += 4 * global->hero[0].speed;
    global->speak[0].pos_button.x += 4 * global->hero[0].speed;
    global->map[0].pos_front.x += 4 * global->hero[0].speed;
    for (int i = 0; i < 2; i++) {
        global->door[i].pos.x += 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[0].sprite, global->door[i].pos);
    }
    for (int i = 0; global->map[0].map_txt[i] != NULL; i++) {
        global->map[i].pos.x += 4 * global->hero[0].speed;
        sfText_setPosition(global->map[i].temp, global->map[i].pos);
    }
    return;
}

void deplace_right(global_t *global)
{
    global->map[0].my_view.left += 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 7;
    global->hero[0].right += 1 * global->hero[0].speed;
    global->png_crest[0].pos.x -= 4 * global->hero[0].speed;
    global->enemy[0].pos.x -= 4 * global->hero[0].speed;
    global->speak[0].pos_button.x -= 4 * global->hero[0].speed;
    global->map[0].pos_front.x -= 4 * global->hero[0].speed;
    for (int i = 0; i < 2; i++) {
        global->door[i].pos.x -= 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[0].sprite, global->door[i].pos);
    }
    for (int i = 0; global->map[0].map_txt[i] != NULL; i++) {
        global->map[i].pos.x -= 4 * global->hero[0].speed;
        sfText_setPosition(global->map[i].temp, global->map[i].pos);
    }
    return;
}

void deplace_in_map(sfRenderWindow *window, global_t *global)
{
    attack_hit_way(global);
    cursor_animation(global);
    sfSprite_setPosition(global->map[0].back, global->map[0].pos_front);
    sfSprite_setPosition(global->map[0].front, global->map[0].pos_front);
    global->hero[0].check_mouv = global->hero[0].check_idle;
    sfMouseButton down = sfKeyDown;
    if (sfKeyboard_isKeyPressed(down) && global->map[0].my_view.top < 1380) {
        if (global->map[0].map_txt[global->hero[0].y + 1][global->hero[0].x] != 'x') {
            deplace_down(global);
        }
    }
    sfMouseButton up = sfKeyUp;
    if (sfKeyboard_isKeyPressed(up) && global->map[0].my_view.top > 0) {
        if (global->map[0].map_txt[global->hero[0].y - 1][global->hero[0].x] != 'x') {
            deplace_up(global);
        }
    }
    sfMouseButton left = sfKeyLeft;
    if (sfKeyboard_isKeyPressed(left) && global->map[0].my_view.left > 0) {
        if (global->map[0].map_txt[global->hero[0].y][global->hero[0].x - 1] != 'x') {
            deplace_left(global);
        }
    }
    sfMouseButton right = sfKeyRight;
    if (sfKeyboard_isKeyPressed(right) && global->map[0].my_view.left < 2420) {
        if (global->map[0].map_txt[global->hero[0].y][global->hero[0].x + 1] != 'x') {
            deplace_right(global);
        }
    }
    if (global->hero[0].down > 11) {
        global->hero[0].y++;
        global->hero[0].down = 0;
    }
    if (global->hero[0].up > 11) {
        global->hero[0].y--;
        global->hero[0].up = 0;
    }
    if (global->hero[0].left > 11) {
        global->hero[0].x--;
        global->hero[0].left = 0;
    }
    if (global->hero[0].right > 11) {
        global->hero[0].x++;
        global->hero[0].right = 0;
    }
    if (global->hero[0].check_attack == 1) {
        global->hero[0].check_mouv = global->hero[0].check_idle + 8;
        attack(window, global, global->hero[0].check_mouv);
        global->hero[0].check_idle = global->hero[0].check_mouv - 8;
    }
    // } else if (global->hero[0].check_mouv >= 0 && global->hero[0].check_mouv < 4)
    if (global->hero[0].check_mouv >= 0 && global->hero[0].check_mouv < 4)
        move(window, global, global->hero[0].check_idle);
    else if (global->hero[0].check_mouv >= 4 && global->hero[0].check_mouv < 8) {
        global->hero[0].check_idle = global->hero[0].check_mouv - 4;
        if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
            global->hero[0].speed = 2;
            move_sprint(window, global, global->hero[0].check_mouv);
        } else {
            global->hero[0].speed = 1;
            move(window, global, global->hero[0].check_mouv);
        }
    }
    sfSprite_setPosition(global->map[0].back, global->map[0].pos_front);
    sfSprite_setPosition(global->png_crest[0].sprite, global->png_crest[0].pos);
    sfSprite_setPosition(global->map[0].front, global->map[0].pos_front);
    move_png_crest(window, global, 0);
    animation_slime(global);
    return;
}
