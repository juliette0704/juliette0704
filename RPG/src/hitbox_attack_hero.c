/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** attack_hitbox
*/

#include "my_rpg.h"

void init_hitbox_attack(global_t *global)
{
    sfIntRect hitbox = {0, 0, 48, 48};
    sfVector2f scale = {2.3, 2.3};
    sfVector2f pos[] = {{960, 636}, {960, 444}, {864, 540}, {1056, 540}};
    for (int i = 0; i < 4; i++) {
        global->hit_attack[i].sprite = make_sprite("sprite/hero/hitbox_attack.png");
        sfSprite_setTextureRect(global->hit_attack[i].sprite, hitbox);
        sfSprite_setPosition(global->hit_attack[i].sprite, pos[i]);
        sfSprite_setScale(global->hit_attack[i].sprite, scale);
    }
}

void attack_hit_way(global_t *global)
{
    sfIntRect hit_range = {0, 0, 32, 32};
    if (sfIntRect_intersects(&global->enemy[0].rect, &global->hit_attack[global->hero[0].check_mouv - 8].rect, &hit_range)) {
        global->enemy[0].stage = 3;
        switch (global->hero[0].check_mouv - 8) {
        case 0:
            global->enemy[0].pos.y += ((605 - global->enemy[0].pos.y) / 5);
            break;
        case 1:
            global->enemy[0].pos.y -= ((605 - global->enemy[0].pos.y) / 5);
            break;
        case 2: 
            global->enemy[0].pos.x -= ((1010- global->enemy[0].pos.x) / 5);
            break;
        case 3:
            global->enemy[0].pos.x += ((1010- global->enemy[0].pos.x) / 5);
            break;
        default:
            break;
        }
    }
}
