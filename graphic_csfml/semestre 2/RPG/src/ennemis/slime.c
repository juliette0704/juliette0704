/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init slime
*/

#include "my_rpg.h"

void new_wave(global_t *global)
{
    sfVector2f pos[] = {{2200, 500}, {1100, 500}, {1100, 1200}, {2200, 1200}, {2200, 800}};
    for (int i = 0; i < global->nb_slime; i++) {
        global->enemy[i].life = 2;
        global->enemy[i].pos = pos[i];
    }
    return;
}

void init_slime(global_t *global)
{
    sfClock *clock;
    float sec;
    sfIntRect rect = {0, 0, 32, 32};
    sfVector2f pos[] = {{2200, 500}, {1100, 500}, {1100, 1200}, {2200, 1200}, {2200, 800}};
    sfIntRect rect_d[] = {{pos[0].x, pos[0].y, 800, 800}, {pos[1].x, pos[1].y, 600, 600}, {pos[2].x, pos[2].y, 600, 600}, {pos[3].x, pos[3].y, 600, 600}, {pos[4].x, pos[4].y, 600, 600}};
    sfVector2f scale = {6, 6};
    sfVector2f origin_d = {400, 400};
    sfVector2f origin = {16, 16};
    global->enemy[0].wave = 0;
    global->enemy[0].damage = 0;
    global->enemy[1].damage = 1;
    for (int i = 0; i < global->nb_slime; i++) {
        global->enemy[i].sprite_d = make_sprite("sprite/hero/hitbox_attack.png");
        sfSprite_setTextureRect(global->enemy[i].sprite_d, rect_d[i]);
        sfSprite_setOrigin(global->enemy[i].sprite_d, origin_d);
        global->enemy[i].detec = rect_d[i];
        global->enemy[i].stage = 0;
        global->enemy[i].sec = sec;
        global->enemy[i].clock = clock;
        global->enemy[i].clock = sfClock_create();
        global->enemy[i].rect = rect;
        global->enemy[i].pos = pos[i];
        global->enemy[i].scale = scale;
        global->enemy[i].pos_x = 886;
        global->enemy[i].pos_x = 800;
        global->enemy[i].life = 2;
        global->enemy[i].sprite = make_sprite("sprite/hero/slime.png");
        sfSprite_setTextureRect(global->enemy[i].sprite, rect);
        sfSprite_setPosition(global->enemy[i].sprite, pos[i]);
        sfSprite_setScale(global->enemy[i].sprite, scale);
        sfSprite_setOrigin(global->enemy[i].sprite, origin);
    }
    return;
}

void idle_slime(global_t *global, int i)
{
    global->enemy[i].rect.top = 0;
    sfSprite_setPosition(global->enemy[i].sprite, global->enemy[i].pos);
    if (global->enemy[i].sec > 0.15) {
        if (global->enemy[i].rect.left < 90)
            global->enemy[i].rect.left += 32;
        else {
            global->enemy[i].rect.left = 0;
            global->enemy[i].stage = 1;
        }
        sfSprite_setTextureRect(global->enemy[i].sprite, global->enemy[i].rect);
        sfClock_restart(global->enemy[i].clock);
    }
    return;
}

void idle2_slime(global_t *global, int i)
{
    global->enemy[i].rect.top = 32;
    sfSprite_setPosition(global->enemy[i].sprite, global->enemy[i].pos);
    if (global->enemy[i].sec > 0.15) {
        if (global->enemy[i].rect.left < 160)
            global->enemy[i].rect.left += 32;
        else {
            global->enemy[i].rect.left = 0;
            global->enemy[i].stage = 2;
        }
        sfSprite_setTextureRect(global->enemy[i].sprite, global->enemy[i].rect);
        sfClock_restart(global->enemy[i].clock);
    }
    return;
}

void attack_slime(global_t *global, int i)
{
    global->enemy[i].rect.top = 64;
    int d;
    sfSprite_setPosition(global->enemy[i].sprite, global->enemy[i].pos);
    if (global->enemy[i].sec > 0.1) {
        if (global->enemy[i].rect.left < 190) {
            global->enemy[i].rect.left += 32;
            int r = rand() % 3;
            if (r == 1)
                d = 20;
            else if (r == 2) 
                d = 15;
            else
                d = 10;
            global->enemy[i].pos.x += ((1010- global->enemy[i].pos.x) / d);
            global->enemy[i].pos.y += ((605 - global->enemy[i].pos.y) / d);
            //global->enemy[0].pos.x += ((1010- global->enemy[0].pos.x) / 7);
            //global->enemy[0].pos_x += global->enemy[0].pos.x / 7;
            //global->enemy[0].pos.y += ((605 - global->enemy[0].pos.y) / 7);
        } else {
            global->enemy[i].rect.left = 0;
            global->enemy[i].stage = rand() % 2;
        }
        sfSprite_setTextureRect(global->enemy[i].sprite, global->enemy[i].rect);
        sfClock_restart(global->enemy[i].clock);
    }
    return;
}

void slime_hit(global_t *global, int i)
{
    for (int i = 0; i < global->nb_slime; i++) {
        global->enemy[i].rect.top = 96;
        sfSprite_setPosition(global->enemy[i].sprite, global->enemy[i].pos);
        if (global->enemy[i].sec > 0.1) {
            if (global->enemy[i].rect.left < 120) {
                global->enemy[i].rect.left += 32;
                slime_pushed_back(global, i, 0);
            } else {
                global->enemy[i].rect.left = 0;
                global->enemy[i].stage = 1;
            }
            sfSprite_setTextureRect(global->enemy[i].sprite, global->enemy[i].rect);
            sfClock_restart(global->enemy[i].clock);
        }
    }
    return;
}

void slime_death(global_t *global, int i)
{
     for (int i = 0; i < global->nb_slime; i++) {
        global->enemy[i].rect.top = 128;
        sfSprite_setPosition(global->enemy[i].sprite, global->enemy[i].pos);
        if (global->enemy[i].sec > 0.15) {
            if (global->enemy[i].rect.left < 120) {
                global->enemy[i].rect.left += 32;
                slime_pushed_back(global, i, 0);
            } else {
                global->enemy[i].rect.left = 0;
                global->enemy[i].stage = 0;
            }
            sfSprite_setTextureRect(global->enemy[i].sprite, global->enemy[i].rect);
            sfClock_restart(global->enemy[i].clock);
        }
    }
    return;
}

void animation_slime(global_t *global)
{
    sfVector2f scale_left = {6, 6};
    sfVector2f scale_right = {-6, 6};
    for (int i = 0; i < global->nb_slime; i++) {
        if (global->enemy[i].pos.x < 1010)
            sfSprite_setScale(global->enemy[i].sprite, scale_left);
        else
            sfSprite_setScale(global->enemy[i].sprite, scale_right);
        if (global->enemy[i].stage == 0)
            idle_slime(global, i);
        else if (global->enemy[i].stage == 1)
            idle2_slime(global, i);
        else if (global->enemy[i].stage == 2) {
            attack_slime(global, i);
        }
    }
}
