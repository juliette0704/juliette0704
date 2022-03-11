/*
** EPITECH PROJECT, 2021
** window.c
** File description:
** main
*/

#include "my.h"
#include "struct.h"

int init_rect_jump(globale_t *all, speed_t *speed)
{
    all->time = sfClock_getElapsedTime(all->clock);
    all->second = all->time.microseconds / 1000000.0;
    if (all->second > 0.09) {
        sfClock_restart(all->clock);
        if (speed->speedjump >= 500) {
            speed->speedjump = 125;
        } else {
            speed->speedjump += 125;
        }
    }
    return speed->speedo;
}

victory_t *sprite_victory(globale_t *all)
{
    victory_t *m = malloc(sizeof(*m));
    char *file[] = {"./victory.png"};
    m->file = file;
    m->s_vic[0] = sfSprite_create();
    m->t_vic[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(m->s_vic[0], m->t_vic[0], sfTrue);
    sfSprite_setPosition(m->s_vic[0], (sfVector2f){0, 0});
    return m;
}