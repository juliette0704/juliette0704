/*
** EPITECH PROJECT, 2022
** draw_dungeon
** File description:
** my_rpg
*/

#include "my_rpg.h"

void boss_door_animation(global_t *global)
{
    if (global->labydoor[1].sec > 0.3) {
        if (global->labydoor[1].rect.left < 350)
            global->labydoor[1].rect.left += 133;
        else {
            global->scene = 6;
            global->labydoor[1].rect.left = 0;
        }
        sfSprite_setTextureRect(global->labydoor[1].sprite, global->labydoor[1].rect);
        sfClock_restart(global->labydoor[1].clock);
    }
    return;
}

void draw_dungeon(global_t *global)
{
    deplace_in_map(global->window, global, 1);
    sfSprite_setPosition(global->labydoor[1].sprite, global->labydoor[1].pos);
    sfSprite_setTextureRect(global->map[1].sprite, global->map[1].my_view);
    sfRenderWindow_drawSprite(global->window, global->map[1].sprite, NULL);
    sfRenderWindow_drawSprite(global->window, global->map[1].front, NULL);
    if (global->inventory[0].is_gold == 0)
        sfRenderWindow_drawSprite(global->window, global->inventory[0].gold_s, NULL);
    sfSprite_setPosition(global->inventory[0].gold_s, global->inventory[0].pos_gold);
    sfRenderWindow_drawSprite(global->window, global->labydoor[1].sprite, NULL);
    sfRenderWindow_drawSprite(global->window, global->hero[global->hero[0].check_mouv].sprite, NULL);
    sfRenderWindow_drawSprite(global->window, global->box[0].sprite, NULL);
    // for (int i = 0; i < 4; i++)
    //     sfRenderWindow_drawSprite(global->window, global->hit_attack[i].sprite, NULL);
    sokoban(global);
    sfMouseButton space = sfKeySpace;
    switch (global->map[1].map_txt[global->hero[1].y][global->hero[1].x]) {
        case '1':
            sfRenderWindow_drawSprite(global->window, global->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space)) {
                global->house[2].is_open = 0;
                global->scene = 0;
            }
            break;
        case '2':
            if (global->inventory[0].is_ball != 1)
            sfRenderWindow_drawSprite(global->window, global->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space)) {
                init_front_map(global, "sprite/map/dungeon_back_wb.png");
                global->inventory[0].is_ball = 1;
            }
            break;
        case '3':
            if (global->inventory[0].is_gold != 1)
                sfRenderWindow_drawSprite(global->window, global->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space)) {
                global->inventory[0].is_gold = 1;
                global->inventory[0].gold_i = 1;
                global->hero[0].damage = 2;
                sfVector2f pos_attack = {850, 430};
                sfIntRect rect_attack = {0, 0, 144, 144};
                sfVector2f scale = {2.3, 2.3};
                global->hero[8].sprite = make_sprite("sprite/hero/attack_down_gold.png");
                global->hero[9].sprite = make_sprite("sprite/hero/attack_up_gold.png");
                global->hero[10].sprite = make_sprite("sprite/hero/attack_left_gold.png");
                global->hero[11].sprite = make_sprite("sprite/hero/attack_right_gold.png");
                for (int i = 8; i < 12; i++) {
                    sfSprite_setTextureRect(global->hero[i].sprite, rect_attack);
                    sfSprite_setScale(global->hero[i].sprite, scale);
                    sfSprite_setPosition(global->hero[i].sprite, pos_attack);
                }
            }
            break;
        case '8':
            if (global->inventory[0].is_ball == 1) {
                sfRenderWindow_drawSprite(global->window, global->house[0].space, NULL);
                if (sfKeyboard_isKeyPressed(space))
                    global->labydoor[1].speed = 1;
                if (global->labydoor[1].speed == 1)
                        boss_door_animation(global);
            }
            break;
        default:
            break;
    }
    return;
}
