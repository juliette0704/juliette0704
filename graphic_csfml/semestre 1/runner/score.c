/*
** EPITECH PROJECT, 2021
** score.c
** File description:
** run
*/

#include "my.h"

char *itoa( int digits)
{
    int temp, len;
    char *str;
    temp = digits;
    len = 0;
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = digits % 10 + '0';
        digits /= 10;
    }
    return str;
}

sfText* init_score(sfVector2f position, int score, globale_t *m, sfText *text)
{
    char *string = itoa(score);
    sfFont *font = sfFont_createFromFile("arial.ttf");
    sfText_setString(text, string);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setCharacterSize(text, 70);
    sfText_setPosition(text, position);
}

void mouse(globale_t *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
    sfMouseButton bout = sfMouseLeft;
    if (sfMouse_isButtonPressed(bout)) {
        if (pos.x > 240 && pos.x < 522 && pos.y > 668 && pos.y < 921)
            sfRenderWindow_close(m->window);
        if (pos.x > 1396 && pos.x < 1660 && pos.y > 677 && pos.y < 925)
            m->menu = 1;
    }
}

globale_t *run(globale_t *m, speed_t *v, int ac, score_t *s, jump_t *jump, char **av)
{
    init_score((sfVector2f){1600, 60}, s->scores, m, m->text);
    s->scores++;
    if (m->i == 0)
        moov_sprite(m, v, jump);
    if (m->i == 1) {
        jump->x = 0;
        m->event.type = sfEvtKeyPressed;
        m->i = 0;
        m->vec = 0;
    }
    print_sprite(m, v, s);
    read_pos(ac, av[1], m);
    sfRenderWindow_drawText(m->window, m->text, NULL);
    return m;
}

void play(globale_t *m, speed_t *v, int ac, score_t *s, jump_t *jump, char **av)
{
    m->count = 0;
    m->o = 0;
    while (sfRenderWindow_isOpen(m->window)) {
        sfRenderWindow_clear(m->window, sfBlack);
        while (sfRenderWindow_pollEvent(m->window, &m->event)) {
            if (m->event.type == sfEvtClosed)
                sfRenderWindow_close(m->window);
        }
        if (m->menu == 1)
            m = run(m, v, ac, s, jump, av);
        else {
            mouse(m);
            menu(m);
        }
        sfRenderWindow_display(m->window);
    }
}