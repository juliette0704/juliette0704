/*
** EPITECH PROJECT, 2022
** rpg boss_slime
** File description:
** boss_slime
*/

#include "my_rpg.h"

void init_slime_boss(global_t *global)
{
    global->boss.rotate = 0;
    global->boss.life = 10;
    global->boss.damage = 0;
    global->boss.growth = 1;
    sfClock *clock;
    float sec;
    global->boss.sec = sec;
    global->boss.clock = clock;
    global->boss.clock = sfClock_create();
    sfIntRect rect = {0, 0, 260, 160};
    sfIntRect rect_attack[] = {{4500, 1500, 250, 500}, {5000, 1500, 250, 500}};
    sfVector2f pos = {5000, 1500};
    sfVector2f scale = {3, 3};
    sfVector2f origin = {140, 100};
    global->hit_boss[0].touch = 0;
    global->hit_boss[1].touch = 0;
    sfVector2f pos_attack[] = {{rect_attack[0].left, rect_attack[0].top}, {rect_attack[1].left, rect_attack[1].top}};
    global->boss.rect = rect;
    for (int i = 0; i < 2; i++) {
        global->hit_boss[i].pos = pos_attack[i];
        global->hit_boss[i].rect = rect_attack[i];
        global->hit_boss[i].sprite = make_sprite("sprite/hero/hitbox_attack.png");
        sfSprite_setTextureRect(global->hit_boss[i].sprite, global->hit_boss[i].rect);
        sfSprite_setPosition(global->hit_boss[i].sprite, pos_attack[i]);
    }
    global->boss.pos = pos;
    global->boss.scale = scale;
    global->boss.sprite = make_sprite("sprite/hero/slime_boss.png");
    sfSprite_setTextureRect(global->boss.sprite, rect);
    sfSprite_setPosition(global->boss.sprite, pos);
    sfSprite_setScale(global->boss.sprite, scale);
    sfSprite_setOrigin(global->boss.sprite, origin);
    global->boss.stage = 1;
    global->hit_boss[0].is_life = 1;

    sfVector2f pos_text = {5000, 1450};
    global->hit_boss[0].pos_life = pos_text;
    sfText *score = make_text(1650, 930, 60, sfYellow);
    global->hit_boss[0].life = score;
    char *score_txt = "0";
    global->hit_boss[0].life_boss_str = score_txt;
    return;
}

void rotate_slime_boss(global_t *global)
{
    sfVector2f scale_left = {-3, 3};
    sfVector2f scale_right = {3, 3};
    if (global->boss.pos.x < 1010) {
        global->boss.scale.x = 3 * (-global->boss.growth);
        global->boss.scale.y = 3 * (global->boss.growth);
        sfSprite_setScale(global->boss.sprite, global->boss.scale);
        global->boss.rotate = 1;
    } else {
        global->boss.scale.x = 3 * global->boss.growth;
        global->boss.scale.y = 3 * (global->boss.growth);
        sfSprite_setScale(global->boss.sprite, global->boss.scale);
        global->boss.rotate = 0;
    }
}

void idle_slime_boss(global_t *global)
{
    global->boss.rect.top = 0;
    sfSprite_setPosition(global->boss.sprite, global->boss.pos);
    if (global->boss.sec > 0.15) {
        if (global->boss.rect.left < 1400)
            global->boss.rect.left += 288;
        else {
            global->boss.rect.left = 0;
            global->boss.stage = 1;
        }
        sfSprite_setTextureRect(global->boss.sprite, global->boss.rect);
        sfClock_restart(global->boss.clock);
    }
    return;
}

void walk_slime_boss(global_t *global)
{
    global->boss.rect.top = 160;
    sfSprite_setPosition(global->boss.sprite, global->boss.pos);
    if (global->boss.sec > 0.1) {
        if (global->boss.rect.left < 3000) {
            rotate_slime_boss(global);
            global->boss.rect.left += 288;
            global->boss.pos.x += ((1010 - global->boss.pos.x) / 12);
            global->boss.pos.y += ((450 - global->boss.pos.y) / 12);
        } else {
            global->boss.rect.left = 0;
        }
        sfSprite_setTextureRect(global->boss.sprite, global->boss.rect);
        sfClock_restart(global->boss.clock);
    }
    return;
}

void attack_slime_boss(global_t *global)
{
    global->boss.rect.top = 320;
    sfSprite_setPosition(global->boss.sprite, global->boss.pos);
    if (global->boss.sec > 0.15) {
        if (global->boss.rect.left < 3700)
            global->boss.rect.left += 288;
        else {
            global->boss.rect.left = 0;
            global->boss.stage = 0;
        }
        sfSprite_setTextureRect(global->boss.sprite, global->boss.rect);
        sfClock_restart(global->boss.clock);
    }
    return;
}

void hit_slime_boss(global_t *global)
{
    global->boss.rect.top = 480;
    sfSprite_setPosition(global->boss.sprite, global->boss.pos);
    if (global->boss.sec > 0.4) {
        if (global->boss.rect.left < 1000) {
            global->boss.rect.left += 288;
        } else {
            global->boss.rect.left = 0;
            global->boss.stage = 1;
        }
        sfSprite_setTextureRect(global->boss.sprite, global->boss.rect);
        sfClock_restart(global->boss.clock);
    }
    return;
}

void death_slime_boss(global_t *global)
{
    global->boss.rect.top = 640;
    sfSprite_setPosition(global->boss.sprite, global->boss.pos);
    if (global->boss.sec > 0.1) {
        if (global->boss.rect.left < 4800) {
            global->boss.rect.left += 288;
        } else {
            global->boss.rect.left = 4608;
            global->boss.damage = 0;
            global->scene = 7;

        }
        sfSprite_setTextureRect(global->boss.sprite, global->boss.rect);
        sfClock_restart(global->boss.clock);
    }
    return;
}

void revive_slime_boss(global_t *global)
{
    global->boss.rect.top = 640;
    sfSprite_setPosition(global->boss.sprite, global->boss.pos);
    if (global->boss.sec > 0.15) {
        if (global->boss.rect.left > 0) {
            rotate_slime_boss(global);
            global->boss.growth *= 1;
            global->boss.rect.left -= 288;
        } else {
            global->boss.rect.left = 0;
            global->boss.stage = 0;
        }
        sfSprite_setScale(global->boss.sprite, global->boss.scale);
        sfSprite_setTextureRect(global->boss.sprite, global->boss.rect);
        sfClock_restart(global->boss.clock);
    }
    return;
}

void animation_slime_boss(global_t *global)
{
    if (global->boss.stage == 0)
        idle_slime_boss(global);
    else if (global->boss.stage == 1)
        walk_slime_boss(global);
    else if (global->boss.stage == 2)
        attack_slime_boss(global);
    else if (global->boss.stage == 3)
        hit_slime_boss(global); 
    else if (global->boss.stage == 4)
        death_slime_boss(global);
    else if (global->boss.stage == 5)
        revive_slime_boss(global);
}