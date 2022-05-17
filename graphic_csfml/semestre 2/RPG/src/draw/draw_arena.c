/*
** EPITECH PROJECT, 2022
** draw_arena
** File description:
** my_rpg
*/

#include "my_rpg.h"

void last_arena(global_t *global)
{
    sfVector2f origin = {16, 16};
    sfVector2f scale = {6, 6};
    sfIntRect rect = {0, 0, 32, 32};
    sfVector2f pos[] = {{2200, 500}, {1100, 500}, {1100, 1200}, {2200, 1200}, {2200, 800}};
    global->enemy[0].wave = 0;
    global->enemy[1].damage = 2;
    global->enemy[0].damage = 0;
    global->history_place = 2;
    for (int i = 0; i < global->nb_slime; i++) {
        global->enemy[i].pos = pos[i];
        global->enemy[i].life = global->life_slime;
        global->enemy[i].sprite = make_sprite("sprite/hero/slimeNRV.png");
        sfSprite_setTextureRect(global->enemy[i].sprite, rect);
        sfSprite_setPosition(global->enemy[i].sprite, pos[i]);
        sfSprite_setScale(global->enemy[i].sprite, scale);
        sfSprite_setOrigin(global->enemy[i].sprite, origin);
    }
    return;
}

void draw_arena(global_t *global)
{
    if (global->history_place == 1)
        last_arena(global);
    sfMouseButton enter = sfKeyEnter;
    deplace_in_map(global->window, global, 3);
    sfSprite_setTextureRect(global->map[3].sprite, global->map[3].my_view);
    sfRenderWindow_drawSprite(global->window, global->map[3].sprite, NULL);
    if (global->map[3].map_txt[global->hero[3].y + 1][global->hero[3].x] == 'o')
        global->enemy[0].damage = 1;
    if (global->enemy[0].damage == 1)
        animation_slime(global);
    int cont = 0;
    for (int i = 0; i < global->nb_slime; i++) {
        if (global->enemy[i].life > 0)
            cont = 1;
        if (global->enemy[0].damage == 1) {
            if (global->enemy[i].life > 0)
                sfRenderWindow_drawSprite(global->window, global->enemy[i].sprite, NULL);
        }
        sfSprite_setPosition(global->enemy[i].sprite_d, global->enemy[i].pos);
        global->enemy[i].detec.left = global->enemy[i].pos.x;
        global->enemy[i].detec.top = global->enemy[i].pos.y;
        sfSprite_setTextureRect(global->enemy[i].sprite_d, global->enemy[i].detec);
    }
    if (global->enemy[0].wave >= 4) {
        cont = 1;
    }
    if (cont == 0) {
        new_wave(global);
        global->enemy[0].wave++;
    }
    check_hit_slime(global);
    sfRenderWindow_drawSprite(global->window, global->hero[global->hero[0].check_mouv].sprite, NULL);
    if (global->enemy[0].wave >= 4)
        sfRenderWindow_drawSprite(global->window, global->map[0].good_job, NULL);
    if (global->map[3].map_txt[global->hero[3].y + 1][global->hero[3].x] == '1') {
        if (global->enemy[0].wave >= 4) {
            sfRenderWindow_drawSprite(global->window, global->house[0].enter, NULL);
            if (sfKeyboard_isKeyPressed(enter)) {
                if (global->history_place != 2)
                    global->history_place = 1;
                global->scene = 0;
            }
        }
    }
    draw_shield(global);
    return;
}
