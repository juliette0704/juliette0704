/*
** EPITECH PROJECT, 2021
** fire_life.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_fire(global_t *g)
{
    g->fire[0].speedfire = 48;
    sfIntRect rect = {0, 0, 48, 48};
    g->fire[0].rect = rect;
    sfVector2f pos = {1200, 2000};

    sfClock *clock;
    float sec;
    g->fire[0].sec_f = sec;
    g->fire[0].clock_f = clock;
    g->fire[0].clock_f = sfClock_create();

    sfIntRect rect_r = {pos.x - 50, pos.y - 50, 400, 400};
    g->fire[0].rect_r = rect_r;
    sfVector2f origin = {100, 100};
    g->fire[0].sprite_r = make_sprite("sprite/hero/hitbox_attack.png");
    sfSprite_setTextureRect(g->fire[0].sprite_r, g->fire[0].rect_r);
    sfSprite_setPosition(g->fire[0].sprite_r, pos);
    sfSprite_setOrigin(g->fire[0].sprite_r, origin);
    g->fire[0].pos = pos;

    g->fire[0].sprite = make_sprite("./sprite/fire/fire.png");
    sfSprite_setTextureRect(g->fire[0].sprite, g->fire[0].rect);
    sfSprite_scale(g->fire[0].sprite, (sfVector2f){2, 2});
    sfSprite_setPosition(g->fire[0].sprite, pos);
    g->fire[0].clock = sfClock_create();
    return;
}

void init_rect_fire(global_t *g)
{
    g->fire[0].rect = (sfIntRect){0, 0, 48, 48};
    g->fire[0].rect.left = g->fire[0].speedfire;
    sfSprite_setTextureRect(g->fire[0].sprite, g->fire[0].rect);
}

void anim_fire(global_t *g)
{
    if (g->fire[0].sec > 0.125) {
        init_rect_fire(g);
        sfClock_restart(g->fire[0].clock);
        if (g->fire[0].speedfire >= 143)
                g->fire[0].speedfire = 0;
        else
            g->fire[0].speedfire += 48;
    }
    g->fire[0].rect_r.left = g->fire[0].pos.x - 200;
    g->fire[0].rect_r.top = g->fire[0].pos.y - 200;
    sfSprite_setTextureRect(g->fire[0].sprite_r, g->fire[0].rect_r);
    sfSprite_setPosition(g->fire[0].sprite_r, (sfVector2f){g->fire[0].pos.x - 50, g->fire[0].pos.y - 50});
    sfSprite_setPosition(g->fire[0].sprite, g->fire[0].pos);
    sfRenderWindow_drawSprite(g->window, g->fire[0].sprite, NULL);
    if (sfIntRect_contains(&g->fire[0].rect_r,  960,  540)) {
        if (g->fire[0].sec_f > 2) {
            if (g->life[0].life > 0)
                g->life[0].life--;
            sfClock_restart(g->fire[0].clock_f);
        }
    }

}
