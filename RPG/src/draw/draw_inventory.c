/*
** EPITECH PROJECT, 2022
** draw_inventory
** File description:
** my_rpg
*/

#include "my_rpg.h"

void inventory_react(global_t *global)
{
    sfVector2f pos;
    if (sfIntRect_contains(&global->inventory[0].rect_quit, global->mouse.x, global->mouse.y)) {
        pos.x = global->inventory[0].pos_quit.x - 10;
        pos.y = global->inventory[0].pos_quit.y - 10;
        sfSprite_setPosition(global->inventory[0].quit, pos);
        sfMouseButton click = sfMouseLeft;
        if (sfMouse_isButtonPressed(click))
            global->inventory[0].is_open = 0;
    } else
        sfSprite_setPosition(global->inventory[0].quit,
    global->inventory[0].pos_quit);
}

void draw_inventory(global_t *global)
{
    sfMouseButton key_i = sfKeyI;
    sfMouseButton escape = sfKeyEscape;
    if (sfKeyboard_isKeyPressed(key_i) && global->inventory[0].is_open == 0)
        global->inventory[0].is_open = 1;
    if (global->inventory[0].is_open == 1) {
        inventory_react(global);
        sfRenderWindow_drawSprite(global->window, global->inventory[0].sprite, NULL);
        sfRenderWindow_drawSprite(global->window, global->inventory[0].quit, NULL);
        if (global->inventory[0].is_ball == 1)
            sfRenderWindow_drawSprite(global->window, global->inventory[0].ball, NULL);
        if (global->inventory[0].gold_i > 0) {
            if (global->inventory[0].gold_i == 1) {
                sfSprite_setPosition(global->inventory[0].gold_s, global->inventory[0].pos_gold_i);
                sfRenderWindow_drawSprite(global->window, global->inventory[0].gold_s, NULL);
            }
            if (global->inventory[0].gold_i == 2) {
                sfVector2f temp = {global->inventory[0].pos_gold_i.x + 20, global->inventory[0].pos_gold_i.y - 20};
                sfSprite_setPosition(global->inventory[0].sword, temp);
                sfRenderWindow_drawSprite(global->window, global->inventory[0].sword, NULL);
            }
        }
        sfRenderWindow_drawSprite(global->window, global->cursor.sprite, NULL);
        if (sfKeyboard_isKeyPressed(escape) && global->inventory[0].is_open == 1)
            global->inventory[0].is_open = 0;
    }
    return;
}
