/*
** EPITECH PROJECT, 2022
** pause
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

int game_pause(global_t *m, int space)
{
    if (m->event.type == sfEvtKeyReleased && m->event.key.code == sfKeySpace && m->space == 1)
        return 0;
    else return 1;
}

int key_pause(global_t *m)
{
    char **av = 0;
    if (m->event.type == sfEvtKeyReleased && !(m->event.key.code == sfKeySpace) && !(m->event.key.code == sfKeyQ) && !(m->event.key.code == sfKeyS) && m->space != 0) {
        m->space = 1;
        return 1;
    }
    if (m->event.type == sfEvtKeyReleased && m->event.key.code == sfKeySpace && m->space == 0) {
        return 1;
    }
    else if (m->event.type == sfEvtKeyReleased && m->event.key.code == sfKeyQ && m->space == 0)
        sfRenderWindow_close(m->window);
    else if (m->event.type == sfEvtKeyReleased && m->event.key.code == sfKeyS && m->space == 0) {
        sfRenderWindow_close(m->window);
        main(1, av);
    }
}

void print_pause(global_t *m)
{
    sfRenderWindow_drawSprite(m->window, m->ennemi->s_enemis[0], NULL);
    sfRenderWindow_drawSprite(m->window, m->ennemi->s_enemis[1], NULL);
    sfRenderWindow_drawSprite(m->window, m->ennemi->s_enemis[2], NULL);
}

void pause_main(global_t *m)
{
    pause_t *pause = malloc(sizeof(pause_t));
    char *file[] = {"./menu/menu_pause.png"};
    pause->s_pause[0] = sfSprite_create();
    pause->t_pause[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(pause->s_pause[0], pause->t_pause[0], sfTrue);
    sfSprite_setPosition(pause->s_pause[0], (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(m->window, pause->s_pause[0], NULL);
}

