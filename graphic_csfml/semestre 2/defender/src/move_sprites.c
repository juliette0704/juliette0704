/*
** EPITECH PROJECT, 2022
** move_sprites
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

void moov_ennemis2(global_t *m)
{
    sfVector2f pos = sfSprite_getPosition(m->ennemi->s_enemis[1]);
    if (pos.x == -500)
        sfSprite_setPosition(m->ennemi->s_enemis[0], (sfVector2f){-250, 240});
    if (pos.x < 300) {
        pos.x += 10;
        sfSprite_setPosition(m->ennemi->s_enemis[1], pos);
    }
    if (pos.x >= 300 && pos.y < 700 && pos.x < 970) {
        pos.y += 15;
        sfSprite_setPosition(m->ennemi->s_enemis[1], pos);
    }
    if (pos.y >= 700 && pos.x < 970) {
        pos.x += 20;
        sfSprite_setPosition(m->ennemi->s_enemis[1], pos);
    }
    if (pos.x >= 970 && pos.y > 170) {
        pos.y -= 30;
        sfSprite_setPosition(m->ennemi->s_enemis[1], pos);
    }
    if (pos.y <= 170 && pos.x >= 970) {
        sfClock_restart(m->clockennemi);
        m->life_game -= 1;
        sfSprite_setPosition(m->ennemi->s_enemis[1], (sfVector2f){-650, 240});
    }
    sfClock_restart(m->clockmoov2);
}

void moov_ennemis(global_t *m)
{
    sfVector2f pos = sfSprite_getPosition(m->ennemi->s_enemis[0]);
    sfVector2f pose = sfSprite_getPosition(m->ennemi->s_enemis[1]);
    if (pos.x < 300 && pose.y == pos.y) {
        pos.x += 10;
        sfSprite_setPosition(m->ennemi->s_enemis[0], pos);
    }
    if (pos.x >= 300 && pos.y < 700 && pos.x < 970) {
        pos.y += 15;
        sfSprite_setPosition(m->ennemi->s_enemis[0], pos);
    }
    if (pos.y >= 700 && pos.x < 970) {
        pos.x += 20;
        sfSprite_setPosition(m->ennemi->s_enemis[0], pos);
    }
    if (pos.x >= 970 && pos.y > 170) {
        pos.y -= 30;
        sfSprite_setPosition(m->ennemi->s_enemis[0], pos);
    }
    if (pos.y <= 170 && pos.x >= 970) {
        m->life_game -= 1;
        sfSprite_setPosition(m->ennemi->s_enemis[0], (sfVector2f){-450, 240});
    }
    sfClock_restart(m->clockmoov);
}

ennemis_t *sprite_ennemi(void)
{
    int j = 0;
    ennemis_t *m = malloc(sizeof(ennemis_t));
    char *file[] = {"./sprite/bossvr.png"
    , "./sprite/dino.png", "./sprite/sorciere.png"
    , "./sprite/squelette.png", "./sprite/squelette2.png"
    , "./sprite/volant.png"};
    m->file = file;
    int x = 0;
    for (int i = 0; i <= 5; i++) {
        m->s_enemis[i] = sfSprite_create();
        m->t_enemis[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_enemis[i], m->t_enemis[j], sfTrue);
        sfSprite_setPosition(m->s_enemis[i], (sfVector2f){-250 + x, 240});
        x = x - 180;
        j++;
    }
    return m;
}