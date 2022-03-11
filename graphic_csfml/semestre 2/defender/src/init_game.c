/*
** EPITECH PROJECT, 2022
** init
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

global_t init_global(global_t m)
{
    m.mode = (sfVideoMode){1920, 1080, 60};
    m.window = sfRenderWindow_create(m.mode, "Run", sfResize | sfClose, NULL);
    m.ennemi = sprite_ennemi();
    m.bg = sprite_bg();
    m.tower = sprite_buildings();
    m.place = sprite_place();
    m.towere1 = sprite_t1(&m);
    m.tower2 = sprite_t2(&m);
    m.tower3 = sprite_t3(&m);
    m.bit = sprite_bit(&m);
    m.minis1 = sprite_mini1(&m);
    m.heart = sprite_heart();
    m.bgtower = sprite_bg_tower();
    m.clockennemi = sfClock_create();
    m.clockskin = sfClock_create();
    m.clockmoov = sfClock_create();
    m.clockskin2 = sfClock_create();
    m.clockmoov2 = sfClock_create();
    m.clockrect = sfClock_create();
    m.j = 0;
    m.speed = 0;
    m.speed2 = 0;
    m.newtower1 = 0;
    m.speedy = 0;
    m.a = 0;
    m.z = 0;
    m.menu = 0;
    m.hight = 0;
    m.space = 0;
    m.firstplace = 0;
    m.ist2 = 0;
    m.secondplace = 0;
    m.score_bit = 10;
    m.toucht2 = 0;
    m.life_en1 = 3;
    m.toucht3 = 0;
    m.life_en2 = 5;
    m.ist1 = 0;
    m.life_game = 8;
    m.level = 0;
    m.isenem2 = 0;
    m.tkt = 0;
    m.lifeno = 3;
    m.lify = 0;
    m.dispmoney = 0;
    m.textheart = sfText_create();
    m.text = sfText_create();
    m.textmoney = sfText_create();
    m.rect = sprite_rect(&m);
    m.textmini1 = sfText_create();
    return m;
}

void init_the_game(void)
{
    global_t m = init_global(m);
    sfRenderWindow_setFramerateLimit(m.window, 70);
    game_loop(&m);
}     