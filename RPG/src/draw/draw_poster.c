/*
** EPITECH PROJECT, 2021
** draw_poster.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void init_text(sfVector2f position, char *string, sfText *text)
{
    sfFont *font = sfFont_createFromFile("font/Pixelletters.ttf");
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 70);
    sfText_setPosition(text, position);
}

void init_poster(global_t *m)
{
    m->panel[0].text = sfText_create();
    sfVector2f pos = {-1000,-500};
    m->panel[0].sprite = make_sprite("sprite/panels/panel1.png");
    for (int i = 0; i < 1; i++) {
        sfSprite_scale(m->panel[0].sprite, (sfVector2f){10, 10});
        sfSprite_setPosition(m->panel[i].sprite, pos);
    }
    init_text((sfVector2f){600, 500}, "hello", m->panel[0].text);
    return;
}

void play_poster(global_t *m)
{
    if (m->map[0].map_txt[m->hero[0].y][m->hero[0].x] == '@') {
        sfRenderWindow_drawSprite(m->window, m->panel[0].sprite, NULL);
        sfRenderWindow_drawText(m->window, m->panel[0].text, NULL);
    }
    
}