/*
** EPITECH PROJECT, 2021
** sprite_bool.c
** File description:
** run
*/

#include "my.h"
#include "struct.h"

void menu(globale_t *m)
{
    menu_t *menue = malloc(sizeof(*menue));
    char *file[] = {"./image.png"};
    menue->s_men[0] = sfSprite_create();
    menue->t_men[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(menue->s_men[0], menue->t_men[0], sfTrue);
    sfSprite_setPosition(menue->s_men[0], (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(m->window, menue->s_men[0], NULL);
}

void play_one(int ac, char **av)
{
    globale_t m = init(m);
    m.count = 1920;
    m.menu = 0;
    jump_t *jump = malloc(sizeof(*jump));
    jump->x = 0;
    jump->y = 820;
    m.text = sfText_create();
    score_t *score = malloc(sizeof(*score));
    score->scores = 0;
    speed_t *v = malloc(sizeof(*v));
    v->speedo = 1;
    v->speedjump = 1;
    m.i = 0;
    sfMusic *bm = sfMusic_createFromFile("froid.wav");
    sfMusic_play(bm);
    sfRenderWindow_setFramerateLimit(m.window, 70);
    play(&m, v, ac, score, jump, av);
    sfMusic_stop(bm);
}

void main(int ac, char **av)
{
    if (ac == 2 && av[1][1] == 'h') {
        my_putstr("\nTouche la barre espace pour sauter par ");
        my_putstr("dessus la cible.\n");
    } else if (ac == 2 && av[1][1] == 'i')
        play_one(ac, av);
    if (ac == 1)
        my_putstr("\nBad arguments\n");
    if (ac == 2 && av[1][1] != 'i')
        play_one(ac, av);
}