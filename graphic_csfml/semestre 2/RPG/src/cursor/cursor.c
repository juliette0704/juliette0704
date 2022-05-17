/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** cursor
*/

#include "my_rpg.h"

void init_cursor(global_t *global)
{
    float sec;
    sfClock *clock;
    global->cursor.sec = sec;
    global->cursor.clock = clock;
    global->cursor.clock = sfClock_create();
    sfIntRect rect = {0, 0, 200, 200};
    sfVector2f origin = {100, 100};
    sfVector2f scale = {0.2, 0.2};

    global->cursor.rect = rect;
    global->cursor.sprite = make_sprite("sprite/hero/cursor.png");
    sfSprite_setTextureRect(global->cursor.sprite, rect);
    sfSprite_setOrigin(global->cursor.sprite, origin);
    sfSprite_setScale(global->cursor.sprite, scale);
    //sfRenderWindow_setMouseCursorVisible(global->window, sfFalse);
}

void cursor_animation(global_t *global)
{
    if (global->cursor.sec > 0.05) {
        if (global->cursor.rect.left < 800)
            global->cursor.rect.left += 200;
        else {
            global->cursor.rect.left = 0;
        }
        sfSprite_setTextureRect(global->cursor.sprite, global->cursor.rect);
        sfClock_restart(global->cursor.clock);
    }
    return;
}