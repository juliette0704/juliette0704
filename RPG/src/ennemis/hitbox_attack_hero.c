/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** attack_hitbox
*/

#include "my_rpg.h"

void init_hitbox_attack(global_t *global)
{
    sfIntRect rect[] = {{890, 650, 250, 150}, {890, 390, 250, 150}, {810, 475, 150, 250}, {1075, 475, 150, 250}, {960, 540, 115, 110}};
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

void check_hit_slime(global_t *global)
{
    sfIntRect hit_range = {0, 0, 24, 24};
    if (sfIntRect_intersects(&global->enemy[0].rect, &global->hit_attack[global->hero[0].check_mouv - 8].rect, &hit_range))
        global->enemy[0].stage = 3;
}

void slime_pushed_back(global_t *global, int i)
{
    switch (i) {
    case 0:
        global->enemy[0].pos.y += 100;
        break;
    case 1:
        global->enemy[0].pos.y -= 100;
        break;
    case 2: 
        global->enemy[0].pos.x -= 100;
        break;
    case 3:
        global->enemy[0].pos.x += 100;
        break;
    default:
        break;
    }
}

// void slime_pushed_back(global_t *global)
// {
//     switch (global->hero[0].check_mouv - 8) {
//     case 0:
//         printf("enter");
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

void test_hitbox(global_t *global)
{
    // if (sfIntRect_contains(&global->hit_attack[0].rect, global->cursor.pos.x, global->cursor.pos.y))
    //     printf("hitbox_down\n");
    // if (sfIntRect_contains(&global->hit_attack[1].rect, global->cursor.pos.x, global->cursor.pos.y))
    //     printf("hitbox_up\n");
    // if (sfIntRect_contains(&global->hit_attack[2].rect, global->cursor.pos.x, global->cursor.pos.y))
    //     printf("hitbox_left\n");
    // if (sfIntRect_contains(&global->hit_attack[3].rect, global->cursor.pos.x, global->cursor.pos.y))
    //     printf("hitbox_right\n");
    // if (sfIntRect_contains(&global->enemy[0].rect, global->cursor.pos.x, global->cursor.pos.y))
    //     printf("enemy\n");
    //for (int i = 0; i < 4; i++) {
    sfMouseButton a = sfKeyA;
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(global->window, global->hit_attack[i].sprite, NULL);
        if (sfIntRect_contains(&global->hit_attack[i].rect,  global->enemy[0].pos.x,  global->enemy[0].pos.y) && sfKeyboard_isKeyPressed(a)) {
            if (global->hero[0].check_mouv == i || global->hero[0].check_mouv == (i + 4)) {
                slime_pushed_back(global, i);
                slime_hit(global);
                sfRenderWindow_drawSprite(global->window, global->hit_attack[i].sprite, NULL);
            }
        }
    }
    sfRenderWindow_drawSprite(global->window, global->hit_attack[4].sprite, NULL);
    if (sfIntRect_contains(&global->hit_attack[4].rect,  global->enemy[0].pos.x,  global->enemy[0].pos.y)) {
        if (global->life[0].life < 9) {
            slime_pushed_back(global, rand() % 4);
            global->life[0].life++;
        }
    }
}
