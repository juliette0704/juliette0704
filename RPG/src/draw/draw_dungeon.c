/*
** EPITECH PROJECT, 2022
** draw_dungeon
** File description:
** my_rpg
*/

#include "my_rpg.h"

void draw_dungeon(global_t *global)
{
    deplace_in_map(global->window, global, 1);
    sfSprite_setTextureRect(global->map[1].sprite, global->map[1].my_view);
    sfRenderWindow_drawSprite(global->window, global->map[1].sprite, NULL);
    sfRenderWindow_drawSprite(global->window, global->map[1].front, NULL);
    if (global->inventory[0].is_gold == 0)
        sfRenderWindow_drawSprite(global->window, global->inventory[0].gold_s, NULL);
    sfSprite_setPosition(global->inventory[0].gold_s, global->inventory[0].pos_gold);
    sfRenderWindow_drawSprite(global->window, global->hero[global->hero[0].check_mouv].sprite, NULL);
    for (int i = 0; i < 4; i++)
        sfRenderWindow_drawSprite(global->window, global->hit_attack[i].sprite, NULL);
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
            sfRenderWindow_drawSprite(global->window, global->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space)) {
                init_front_map(global, "sprite/map/dungeon_back_wb.png");
                global->map[1].map_txt = my_str_to_word_array(open_map("parsing/dungeon_after"), '\n');
                global->inventory[0].is_ball = 1;
            }
            // if (global->house[2].is_open == 1) {
            //     global->scene = 0;
            //     global->house[2].is_open = 0;
            // }
            break;
        case '3':
            if (global->inventory[0].is_gold != 1)
                sfRenderWindow_drawSprite(global->window, global->house[0].space, NULL);
            if (sfKeyboard_isKeyPressed(space)) {
                global->inventory[0].is_gold = 1;
                global->inventory[0].gold_i = 1;
            }
            break;
        default:
            break;
    }
    return;
}
