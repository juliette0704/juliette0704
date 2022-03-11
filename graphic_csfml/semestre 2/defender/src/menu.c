/*
** EPITECH PROJECT, 2022
** menu
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

void display_menu_tower(global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->bgtower->s_bgtower[1], NULL);
    print_tower(m);
}

void mouse_menu(global_t *m)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(m->window);
    sfMouseButton bout = sfMouseLeft;
    if (sfMouse_isButtonPressed(bout)) {
        if (pos.x > 1572 && pos.x < 1854 && pos.y > 388 && pos.y < 513)
            sfRenderWindow_close(m->window);
        if (pos.x > 80 && pos.x < 350 && pos.y > 375 && pos.y < 485)
            m->menu = 1;
    }
}

void menu(global_t *m)
{
    menu_t *menue = malloc(sizeof(*menue));
    char *file[] = {"./menu/menu.png"};
    menue->s_men[0] = sfSprite_create();
    menue->t_men[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(menue->s_men[0], menue->t_men[0], sfTrue);
    sfSprite_setPosition(menue->s_men[0], (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(m->window, menue->s_men[0], NULL);
}

