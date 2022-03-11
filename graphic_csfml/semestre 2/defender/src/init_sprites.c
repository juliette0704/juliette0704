/*
** EPITECH PROJECT, 2022
** init_sprites
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

void init_rect_sprite2(global_t *m)
{
    int y = m->hight;
    m->rectennemis2 = (sfIntRect){0, y, 209, 250};
    m->rectennemis2.left = m->speed2;
    sfSprite_setTextureRect(m->ennemi->s_enemis[1], m->rectennemis2);
}

void init_rect_sprite1(global_t *m)
{
    int y = m->hight;
    m->rectennemis = (sfIntRect){0, y, 225, 250};
    m->rectennemis.left = m->speed;
    sfSprite_setTextureRect(m->ennemi->s_enemis[0], m->rectennemis);
}
minis1_t *sprite_mini1(global_t *t)
{
    minis1_t *m = malloc(sizeof(minis1_t));
    char *file[] = {"./sprite/mini1.png"};
    m->file = file;
    m->s_minis1[0] = sfSprite_create();
    m->t_minis1[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(m->s_minis1[0], m->t_minis1[0], sfTrue);
    sfSprite_setPosition(m->s_minis1[0], (sfVector2f){50, 155});
    return m;
}