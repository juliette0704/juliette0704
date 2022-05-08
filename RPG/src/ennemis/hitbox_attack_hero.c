/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** attack_hitbox
*/

#include "my_rpg.h"

void init_hitbox_attack(global_t *global)
{
    sfIntRect rect[] = {{890, 650, 250, 200}, {890, 340, 250, 200}, {760, 475, 200, 250}, {1075, 475, 200, 250}, {960, 540, 115, 110}};
    sfVector2f pos[] = {{rect[0].left, rect[0].top}, {rect[1].left, rect[1].top}, {rect[2].left, rect[2].top}, {rect[3].left, rect[3].top}, {rect[4].left, rect[4].top}};
    global->hit_attack[4].sprite = make_sprite("sprite/hero/my_hit.png");
    global->hit_attack[4].rect = rect[4];
    sfSprite_setTextureRect(global->hit_attack[4].sprite, rect[4]);
    sfSprite_setPosition(global->hit_attack[4].sprite, pos[4]);
    for (int i = 0; i < 4; i++) {
        global->hit_attack[i].sprite = make_sprite("sprite/hero/hitbox_attack.png");
        global->hit_attack[i].rect = rect[i];
        sfSprite_setTextureRect(global->hit_attack[i].sprite, rect[i]);
        sfSprite_setPosition(global->hit_attack[i].sprite, pos[i]);
        //sfSprite_setScale(global->hit_attack[i].sprite, scale);
    }
    global->hit_attack[4].rect = rect[4];
}

void slime_pushed_back(global_t *global, int i, int k)
{
    switch (i) {
    case 0:
        global->enemy[k].pos.y += 300;
        break;
    case 1:
        global->enemy[k].pos.y -= 300;
        break;
    case 2: 
        global->enemy[k].pos.x -= 300;
        break;
    case 3:
        global->enemy[k].pos.x += 300;
        break;
    default:
        break;
    }
}

// void slime_pushed_back(global_t *global, int i)
// {
//     switch (global->hero[0].check_mouv - 8) {
//     case 0:
//         global->enemy[0].pos.y += 20;
//         break;
//     case 1:
//         global->enemy[0].pos.y -= 20;
//         break;
//     case 2: 
//         global->enemy[0].pos.x -= 20;
//         break;
//     case 3:
//         global->enemy[0].pos.x += 20;
//         break;
//     default:
//         break;
//     }
// }

void check_hit_slime(global_t *global)
{
    for (int i = 0; i < 4; i++) {
        //sfRenderWindow_drawSprite(global->window, global->hit_attack[i].sprite, NULL);
        for (int k = 0; k < global->nb_slime; k++) {
            if (sfIntRect_contains(&global->hit_attack[i].rect, global->enemy[k].pos.x,  global->enemy[k].pos.y)) {
                if (global->attack == 1) {
                    if (global->hero[0].check_mouv == (i + 8) || global->hero[0].check_mouv == (i + 12)) {
                        slime_pushed_back(global, i, k);
                        sfSprite_setPosition(global->enemy[k].sprite, global->enemy[k].pos);
                        global->enemy[k].life -= global->hero[0].damage;
                    }
                }
            }
        }
    }
    global->attack = 0;
    for (int k = 0; k < global->nb_slime; k++) {
        if (sfIntRect_contains(&global->hit_attack[4].rect,  global->enemy[k].pos.x,  global->enemy[k].pos.y)) {
            if (global->life[0].life < 9) {
                slime_pushed_back(global, rand() % 4, k);
                if (global->enemy[k].life > 0 && global->shield[0].active == 0 && global->enemy[0].damage == 1)
                    global->life[0].life += global->enemy[1].damage;
            }
            if (global->life[0].life >= 9)
                global->scene = -2;
        }
    }
}

void check_hit_slime_boss(global_t *global)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(global->window, global->hit_attack[i].sprite, NULL);
        if (sfIntRect_contains(&global->hit_attack[i].rect, global->boss.pos.x, global->boss.pos.y)) {
            if (global->attack == 1) {
                if (global->hero[0].check_mouv == (i + 8) || global->hero[0].check_mouv == (i + 12)) {
                    global->boss.stage = 3;
                    global->boss.life -= global->hero[0].damage;
                }
            }
        }
    }
    global->attack = 0;
    if (global->boss.stage == 2) {
        // printf("attack\n");
        if (sfIntRect_contains(&global->hit_attack[4].rect, global->boss.pos.x - (50 * global->boss.scale.x), global->boss.pos.y - (24 * global->boss.scale.y)) && global->boss.rotate == 1)
            // printf("attack_left hit\n");
            global->life[0].life += global->boss.damage;
        if (sfIntRect_contains(&global->hit_attack[4].rect, global->boss.pos.x + 50, global->boss.pos.y - 24) && global->boss.rotate == 0)
            // printf("attack_right hit\n");
            global->life[0].life += global->boss.damage;
    }
}
