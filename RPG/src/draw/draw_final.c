/*
** EPITECH PROJECT, 2022
** draw_final
** File description:
** my_rpg
*/

#include "my_rpg.h"

void print_life(global_t *global)
{
    if (global->hit_boss[0].life_boss > 0) {
        global->hit_boss[0].life_boss_str = my_itoa(global->hit_boss[0].life_boss);
        sfText_setString(global->hit_boss[0].life, global->hit_boss[0].life_boss_str);
    } else {
        global->hit_boss[0].life_boss_str = "0";
        sfText_setString(global->hit_boss[0].life, global->hit_boss[0].life_boss_str);
    }
    return;
}

void draw_final(global_t *global)
{
    deplace_in_map(global->window, global, 4);
    if (global->map[4].map_txt[global->hero[4].y + 1][global->hero[4].x] == 'o' && global->hit_boss[0].life_boss > 0)
        global->boss.damage = 1;
    sfSprite_setTextureRect(global->map[4].sprite, global->map[4].my_view);
    sfRenderWindow_drawSprite(global->window, global->map[4].sprite, NULL);
    if (global->boss.damage == 1) {
        animation_slime_boss(global);
        sfRenderWindow_drawSprite(global->window, global->boss.sprite, NULL);
        global->hit_boss[0].pos.x = global->boss.pos.x - 250;
        global->hit_boss[0].pos.y = global->boss.pos.y - 190;
        global->hit_boss[1].pos.x = global->boss.pos.x;
        global->hit_boss[1].pos.y = global->boss.pos.y - 190;
        for (int i = 0; i < 2; i++) {
            global->hit_boss[i].rect.left = global->hit_boss[i].pos.x;
            global->hit_boss[i].rect.top = global->hit_boss[i].pos.y;
            sfSprite_setPosition(global->hit_boss[i].sprite, global->hit_boss[i].pos);
            sfSprite_setTextureRect(global->hit_boss[i].sprite, global->hit_boss[i].rect);
            //sfRenderWindow_drawSprite(global->window, global->hit_boss[i].sprite, NULL);
            if (sfIntRect_contains(&global->hit_boss[i].rect, 960, 540) && global->boss.stage == 1) {
                //sfRenderWindow_drawSprite(global->window, global->hit_boss[i].sprite, NULL);
                global->boss.stage = 2;
            }
            if (sfIntRect_contains(&global->hit_boss[i].rect, 960, 540) && global->boss.stage == 2) {
                if (global->boss.rect.left > 3700 && global->shield[0].active == 0)
                    global->hit_boss[0].touch = 1;
            }
            if (sfIntRect_contains(&global->hit_boss[i].rect, 960, 540)) {
                if (global->attack == 1)
                    global->hit_boss[1].touch = 1;
            }
        }
        global->attack = 0;
        if (global->hit_boss[0].touch == 1) {
            if (global->life[0].life >= 5)
                global->scene = -5;
            if (global->life[0].life < 9 && global->life[0].life < 5)
                global->life[0].life += 5;
            global->hit_boss[0].touch = 0;
            global->boss.stage = 0;
        }
        if (global->hit_boss[1].touch == 1) {
            global->hit_boss[0].life_boss -= 5;
            global->hit_boss[1].touch = 0;
        }
        if (global->hit_boss[0].life_boss <= 0)
            global->boss.stage = 4;
    }
    for (int i = 0; i < 5; i++)
        fire_particle(global, i);
    sfRenderWindow_drawSprite(global->window, global->hero[global->hero[0].check_mouv].sprite, NULL);
    print_life(global);
    global->hit_boss[0].pos_life.x = global->boss.pos.x - 20;
    global->hit_boss[0].pos_life.y = global->boss.pos.y - 150;
    sfText_setPosition(global->hit_boss[0].life, global->hit_boss[0].pos_life);
    if (global->boss.damage == 1)
        sfRenderWindow_drawText(global->window, global->hit_boss[0].life, NULL);
    draw_shield(global);
    return;
}
