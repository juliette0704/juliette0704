/*
** EPITECH PROJECT, 2022
** game_over
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_game_over(global_t *global)
{
    global->intro[1].sprite = make_sprite("sprite/game_over/game_over.png");
    global->intro[1].is_done = 0;
    sfColor color = sfSprite_getColor(global->intro[1].sprite);
    color.a = 1;
    sfSprite_setColor(global->intro[1].sprite, color);
    return;
}

void draw_game_over(global_t *global)
{
    sfMouseButton x = sfKeyX;
    sfColor color = sfSprite_getColor(global->intro[1].sprite);
    if (global->intro[0].sec > 0.01) {
        if (color.a < 250)
            color.a += 1;
        if (sfKeyboard_isKeyPressed(x)) {
            init_slime(global);
            sfIntRect m_view = {0, 0, 960, 540};
            global->map[3].my_view = m_view;
            global->scene = 5;
            global->hero[3].check_mouv = 0;
            global->hero[3].check_idle = 0;
            global->hero[3].check_attack = 0;
            global->hero[3].x = 1;
            global->hero[3].y = 1;
            global->hero[3].down = 0;
            global->hero[3].up = 0;
            global->hero[3].left = 0;
            global->hero[3].right = 0;
            global->hero[3].speed = 0;
            global->life[0].life = 0;
        }
        sfClock_restart(global->intro[0].clock);
    }
    sfSprite_setColor(global->intro[1].sprite, color);
    sfRenderWindow_drawSprite(global->window, global->intro[1].sprite, NULL);
    return;
}

void game_over_final(global_t *global)
{
    sfMouseButton x = sfKeyX;
    sfColor color = sfSprite_getColor(global->intro[1].sprite);
    if (global->intro[0].sec > 0.01) {
        if (color.a < 250)
            color.a += 1;
        if (sfKeyboard_isKeyPressed(x)) {
            sfIntRect m_view = {0, 0, 960, 540};
            global->map[4].my_view = m_view;
            global->scene = 6;
            global->hero[4].check_mouv = 0;
            global->hero[4].check_idle = 0;
            global->hero[4].check_attack = 0;
            global->hero[4].x = 1;
            global->hero[4].y = 1;
            global->hero[4].down = 0;
            global->hero[4].up = 0;
            global->hero[4].left = 0;
            global->hero[4].right = 0;
            global->hero[4].speed = 0;
            global->life[0].life = 0;
            init_slime_boss(global);
            global->hit_boss[0].life_boss = global->hit_boss[1].life_boss;
        }
        sfClock_restart(global->intro[0].clock);
    }
    sfSprite_setColor(global->intro[1].sprite, color);
    sfRenderWindow_drawSprite(global->window, global->intro[1].sprite, NULL);
    return;
}
