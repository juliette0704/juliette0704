/*
** EPITECH PROJECT, 2021
** init_night.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_quest(global_t *m)
{
    m->quest[0].onetime = 0;
    m->quest[0].t = 0;
    m->quest[0].clock = sfClock_create();
    sfVector2f pos = {1000,1000};
    m->quest[0].pos = pos;
    m->quest[0].sprite = make_sprite("sprite/queste/queste.png");
    m->quest[0].rect = (sfIntRect){1000, 1000, 180, 470};
    for (int i = 0; i < 1; i++)
        sfSprite_setPosition(m->quest[i].sprite, pos);
    m->quest[0].text = sfText_create();
    m->quest[0].text2 = sfText_create();
    char *text1 = "Hello again my friend! Welcome in our planet! if you find the MOM, she will\ngive you your thick to can fight the slims\n TIPS: The mom likes flowers";
    char *text2 = "Good job little Warrior! Now, you can go start to fight the slime... I think\nyou can find them in an arena";
    init_text((sfVector2f){69, 600}, text1, m->quest[0].text);
    init_text((sfVector2f){69, 600}, text2, m->quest[0].text2);
    return;
}

void draw_quest_hero(global_t *m)
{
    m->quest[0].sec = make_clock(m->quest[0].clock);
    sfTime t = sfClock_getElapsedTime(m->quest[0].clock);
    float sec = t.microseconds / 1000000.0;
    if (m->quest[0].onetime == 0)
        m->quest[0].ecou = sec;
    m->quest[0].onetime = 1;
    if (sec < m->quest[0].ecou + 10) {
    // printf("%f\n", m->quest[0].sec);
        sfRenderWindow_drawSprite(m->window, m->speak[0].sprite, NULL);
        sfRenderWindow_drawText(m->window, m->quest[0].text, NULL);
    }
    // if (m->quest[0].sec < 10) {
    // }
}

void draw_mom_quest(global_t *m)
{
    sfTime t = sfClock_getElapsedTime(m->quest[0].clock);
    float sec = t.microseconds / 1000000.0;
    if (m->quest[0].onetime == 1)
        m->quest[0].ecou = sec;
    m->quest[0].onetime = 2;
    if (sec < m->quest[0].ecou + 10) {
        sfRenderWindow_drawSprite(m->window, m->speak[0].sprite, NULL);
        sfRenderWindow_drawText(m->window, m->quest[0].text2, NULL);
    }
}

void draw_quest(global_t *m)
{
    if (m->quest[0].t == 0 && m->map[0].map_txt[m->hero[0].x][m->hero[0].y] == 'q') {
        m->quest[0].t = 1;
    }
    if (m->quest[0].t == 1)
        draw_quest_hero(m);
    if (m->quest[0].t == 2) {
        draw_mom_quest(m);
    }
}