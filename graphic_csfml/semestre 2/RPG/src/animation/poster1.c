/*
** EPITECH PROJECT, 2021
** poster.c
** File description:
** my_defender
*/

#include "my_rpg.h"

void init_text(sfVector2f position, char *string, global_t *m)
{
    sfFont *font = sfFont_createFromFile("font/Pixelletters.ttf");
    sfText_setString(m->panel[0].text, string);
    sfText_setFont(m->panel[0].text, font);
    sfText_setColor(m->panel[0].text, sfBlack);
    sfText_setCharacterSize(m->panel[0].text, 70);
    sfText_setPosition(m->panel[0].text, position);
}

void init_poster1(global_t *m)
{
    sfVector2f pos = {-1000,-500};
    m->panel[0].sprite = make_sprite("sprite/panels/panel1.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_scale(m->panel[0].sprite, (sfVector2f){10, 10});
        sfSprite_setPosition(m->panel[i].sprite, pos);
    }
    init_text((sfVector2f){600, 500}, "hello", m);
    return;
}

void play_poster(global_t *m)
{
    if (m->map[0].map_txt[m->hero[0].y][m->hero[0].x] == '@') {
        sfRenderWindow_drawSprite(m->window, m->panel[0].sprite, NULL);
        sfRenderWindow_drawText(m->window, m->panel[0].text, NULL);
    }
    
}