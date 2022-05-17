/*
** EPITECH PROJECT, 2022
** deplace_hero
** File description:
** my_rpg
*/

#include "my_rpg.h"

void down_map(global_t *global)
{
    global->png_crest[0].pos.y -= 4 * global->hero[0].speed;
    global->enemy[0].pos.y -= 4 * global->hero[0].speed;
    global->fire[0].pos.y -= 4 * global->hero[0].speed;
    global->quest[0].pos.y -= 4 * global->hero[0].speed;
    if (global->box[0].take != 1) {
        global->box[0].pos.y -= 4 * global->hero[0].speed;
        sfSprite_setPosition(global->box[0].sprite, global->box[0].pos);
    }

    global->speak[0].pos_button.y -= 4 * global->hero[0].speed;
    for (int i = 0; i < 3; i++) {
        global->door[i].pos.y -= 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[i].sprite, global->door[i].pos);
    }
    return;
}

void deplace_down(global_t *global, int j)
{
    global->map[j].my_view.top += 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 4;
    global->hero[j].down += 1 * global->hero[0].speed;
    global->map[j].pos_front.y -= 4 * global->hero[0].speed;
    if (j == 0)
        down_map(global);
    if (j == 1) {
        global->labydoor[1].pos.y -= 4 * global->hero[0].speed;
        global->inventory[0].pos_gold.y -= 4 * global->hero[0].speed;
        global->box[0].pos.y -= 4 * global->hero[0].speed;
        global->labydoor[0].pos.y -= 4 * global->hero[0].speed;
    }
    if (j == 3) {
        for (int k = 0; k < global->nb_slime; k++) {
            global->enemy[k].pos.y -= 4 * global->hero[0].speed;
        }
    }
    if (j == 2) {
        global->mentor[0].pos.y -= 4 * global->hero[0].speed;
    }
    if (j == 4) {
        global->boss.pos.y -= 4 * global->hero[0].speed;
    }
    // for (int k = 0; k < 4; k++)
    //     global->hit_attack[k].rect.top += 4 * global->hero[0].speed;
    // for (int i = 0; global->map[j].map_txt[i] != NULL; i++) {
    //     global->map[j].pos.y -= 4 * global->hero[0].speed;
    //     //sfText_setPosition(global->map[j].temp, global->map[j].pos);
    // }
    return;
}

void up_map(global_t *global)
{
    global->png_crest[0].pos.y += 4 * global->hero[0].speed;
    global->enemy[0].pos.y += 4 * global->hero[0].speed;
    global->fire[0].pos.y += 4 * global->hero[0].speed;
    global->quest[0].pos.y += 4 * global->hero[0].speed;
    if (global->box[0].take != 4) {
        global->box[0].pos.y += 4 * global->hero[0].speed;
        sfSprite_setPosition(global->box[0].sprite, global->box[0].pos);
    }

    global->speak[0].pos_button.y += 4 * global->hero[0].speed;
    for (int i = 0; i < 3; i++) {
        global->door[i].pos.y += 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[i].sprite, global->door[i].pos);
    }
    return;
}

void deplace_up(global_t *global, int i)
{
    global->map[i].my_view.top -= 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 5;
    global->hero[i].up += 1 * global->hero[0].speed;
    global->map[i].pos_front.y += 4 * global->hero[0].speed;
    if (i == 0)
        up_map(global);
    if (i == 1) {
        global->labydoor[1].pos.y += 4 * global->hero[0].speed;
        global->inventory[0].pos_gold.y += 4 * global->hero[0].speed;
        global->box[0].pos.y += 4 * global->hero[0].speed;
        global->labydoor[0].pos.y += 4 * global->hero[0].speed;
    }
    if (i == 3) {
        for (int k = 0; k < global->nb_slime; k++) {
            global->enemy[k].pos.y += 4 * global->hero[0].speed;
        }
    }
    if (i == 2) {
        global->mentor[0].pos.y += 4 * global->hero[0].speed;
    }
    if (i == 4) {
        global->boss.pos.y += 4 * global->hero[0].speed;
    }
    // for (int k = 0; k < 4; k++)
    //     global->hit_attack[k].rect.top -= 4 * global->hero[0].speed;
    // for (int j = 0; global->map[i].map_txt[j] != NULL; j++) {
    //     global->map[j].pos.y += 4 * global->hero[0].speed;
    //     //sfText_setPosition(global->map[j].temp, global->map[j].pos);
    // }
    return;
}

void left_map(global_t *global)
{
    global->png_crest[0].pos.x += 4 * global->hero[0].speed;
    global->enemy[0].pos.x += 4 * global->hero[0].speed;
    global->fire[0].pos.x += 4 * global->hero[0].speed;
    global->quest[0].pos.x += 4 * global->hero[0].speed;
    if (global->box[0].take != 2) {
        global->box[0].pos.x += 4 * global->hero[0].speed;
        sfSprite_setPosition(global->box[0].sprite, global->box[0].pos);
    }

    global->speak[0].pos_button.x += 4 * global->hero[0].speed;
    for (int i = 0; i < 3; i++) {
        global->door[i].pos.x += 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[i].sprite, global->door[i].pos);
    }
    return;
}

void deplace_left(global_t *global, int i)
{
    global->map[i].my_view.left -= 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 6;
    global->hero[i].left += 1 * global->hero[0].speed;
    global->map[i].pos_front.x += 4 * global->hero[0].speed;
    if (i == 0)
        left_map(global);
    if (i == 1) {
        global->labydoor[1].pos.x += 4 * global->hero[0].speed;
        global->inventory[0].pos_gold.x += 4 * global->hero[0].speed;
        global->box[0].pos.x += 4 * global->hero[0].speed;
        global->labydoor[0].pos.x += 4 * global->hero[0].speed;
    }
    if (i == 3) {
        for (int k = 0; k < global->nb_slime; k++) {
            global->enemy[k].pos.x += 4 * global->hero[0].speed;
        }
    }
    if (i == 2) {
        global->mentor[0].pos.x += 4 * global->hero[0].speed;
    }
    if (i == 4) {
        global->boss.pos.x += 4 * global->hero[0].speed;
    }
    // for (int k = 0; k < 4; k++)
    //     global->hit_attack[k].rect.left -= 4 * global->hero[0].speed;
    // for (int j = 0; global->map[i].map_txt[i] != NULL; j++) {
    //     global->map[j].pos.x += 4 * global->hero[0].speed;
    //     //sfText_setPosition(global->map[j].temp, global->map[j].pos);
    // }
    return;
}

void right_map(global_t *global)
{
    global->png_crest[0].pos.x -= 4 * global->hero[0].speed;
    global->enemy[0].pos.x -= 4 * global->hero[0].speed;
    global->fire[0].pos.x -= 4 * global->hero[0].speed;
    global->quest[0].pos.x -= 4 * global->hero[0].speed;
    if (global->box[0].take != 3) {
        global->box[0].pos.x -= 4 * global->hero[0].speed;
        sfSprite_setPosition(global->box[0].sprite, global->box[0].pos);
    }
    global->enemy[0].pos.x -= 4 * global->hero[0].speed;
    global->speak[0].pos_button.x -= 4 * global->hero[0].speed;
    for (int i = 0; i < 3; i++) {
        global->door[i].pos.x -= 4 * global->hero[0].speed;
        sfSprite_setPosition(global->door[i].sprite, global->door[i].pos);
    }
}

void deplace_right(global_t *global, int i)
{
    global->map[i].my_view.left += 2 * global->hero[0].speed;
    global->hero[0].check_mouv = 7;
    global->hero[i].right += 1 * global->hero[0].speed;
    global->map[i].pos_front.x -= 4 * global->hero[0].speed;
    // for (int k = 0; k < 4; k++)
    //     global->hit_attack[k].rect.left += 4 * global->hero[0].speed;
    if (i == 0)
        right_map(global);
    if (i == 1) {
        global->labydoor[1].pos.x -= 4 * global->hero[0].speed;
        global->inventory[0].pos_gold.x -= 4 * global->hero[0].speed;
        global->box[0].pos.x -= 4 * global->hero[0].speed;
        global->labydoor[0].pos.x -= 4 * global->hero[0].speed;
    }
    if (i == 3) {
        for (int k = 0; k < global->nb_slime; k++) {
            global->enemy[k].pos.x -= 4 * global->hero[0].speed;
        }
    }
    if (i == 2) {
        global->mentor[0].pos.x -= 4 * global->hero[0].speed;
    }
    if (i == 4) {
        global->boss.pos.x -= 4 * global->hero[0].speed;
    }
    return;
}

void deplace_in_map(sfRenderWindow *window, global_t *global, int i)
{
    cursor_animation(global);
    sfSprite_setPosition(global->map[0].back, global->map[0].pos_front);
    sfSprite_setPosition(global->map[0].front, global->map[0].pos_front);
    global->hero[0].check_mouv = global->hero[0].check_idle;
    sfMouseButton down = sfKeyDown;
    if (sfKeyboard_isKeyPressed(down) && global->map[i].my_view.top < 1180) {
        if (global->map[i].map_txt[global->hero[i].y + 1][global->hero[i].x] != 'x') {
            deplace_down(global, i);
        }
    }
    sfMouseButton up = sfKeyUp;
    if (sfKeyboard_isKeyPressed(up) && global->map[i].my_view.top > 0) {
        if (global->map[i].map_txt[global->hero[i].y - 1][global->hero[i].x] != 'x') {
            deplace_up(global, i);
        }
    }
    sfMouseButton left = sfKeyLeft;
    if (sfKeyboard_isKeyPressed(left) && global->map[i].my_view.left > 0) {
        if (global->map[i].map_txt[global->hero[i].y][global->hero[i].x - 1] != 'x') {
            deplace_left(global, i);
        }
    }
    sfMouseButton right = sfKeyRight;
    if (sfKeyboard_isKeyPressed(right) && global->map[i].my_view.left < 1900) {
        if (global->map[i].map_txt[global->hero[i].y][global->hero[i].x + 1] != 'x') {
            deplace_right(global, i);
        }
    }
    if (global->hero[i].down > 11) {
        global->hero[i].y++;
        global->hero[i].down = 0;
    }
    if (global->hero[i].up > 11) {
        global->hero[i].y--;
        global->hero[i].up = 0;
    }
    if (global->hero[i].left > 11) {
        global->hero[i].x--;
        global->hero[i].left = 0;
    }
    if (global->hero[i].right > 11) {
        global->hero[i].x++;
        global->hero[i].right = 0;
    }
    if (global->hero[0].check_attack == 1) {
        global->hero[0].check_mouv = global->hero[0].check_idle + 8;
        attack(window, global, global->hero[0].check_mouv);
        global->hero[0].check_idle = global->hero[0].check_mouv - 8;
    }
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
    sfSprite_setPosition(global->map[i].front, global->map[i].pos_front);
    move_png_crest(window, global, 0);
    animation_shield(global);
    return;
}
