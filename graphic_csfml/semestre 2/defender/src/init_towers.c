/*
** EPITECH PROJECT, 2022
** init_towers
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

buildings_t *sprite_buildings(void)
{
    int j = 0;
    buildings_t *m = malloc(sizeof(buildings_t));
    char *file[] = {"./tower/tower1.png"
    , "./tower/tower2.png", "./tower/tower3.png"
    , "./tower/tower4.png"};
    m->file = file;
    int x = 0;
    for (int i = 0; i <= 3; i++) {
        m->s_bui[i] = sfSprite_create();
        m->t_bui[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_bui[i], m->t_bui[j], sfTrue);
        sfSprite_setPosition(m->s_bui[i], (sfVector2f){1510, 510 + x});
        x = x + 130;
        j++;
    }
    return m;
}

tower3_t *sprite_t3(global_t *t)
{
    int j = 0;
    tower3_t *m = malloc(sizeof(tower3_t));
    char *file[] = {"./tower/tower3.png"
    , "./tower/tower3.png","./tower/tower3.png"
    , "./tower/tower3.png", "./tower/tower3.png"};
    m->file = file;
    for (int i = 0; i <= 4; i++) {
        m->s_t3[i] = sfSprite_create();
        m->t_t3[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_t3[i], m->t_t3[j], sfTrue);
        sfSprite_setPosition(m->s_t3[i], (sfVector2f){-100, -200});
        j++;
    }
    return m;
}

tower2_t *sprite_t2(global_t *t)
{
    int j = 0;
    tower2_t *m = malloc(sizeof(tower2_t));
    char *file[] = {"./tower/tower2.png"
    , "./tower/tower2.png","./tower/tower2.png"
    , "./tower/tower2.png", "./tower/tower2.png"};
    m->file = file;
    for (int i = 0; i <= 4; i++) {
        m->s_t2[i] = sfSprite_create();
        m->t_t2[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_t2[i], m->t_t2[j], sfTrue);
        sfSprite_setPosition(m->s_t2[i], (sfVector2f){-100, -200});
        j++;
    }
    return m;
}

tower1_t *sprite_t1(global_t *t)
{
    int j = 0;
    tower1_t *m = malloc(sizeof(tower1_t));
    char *file[] = {"./tower/tower1.png"
    , "./tower/tower1.png","./tower/tower1.png"
    , "./tower/tower1.png", "./tower/tower1.png"};
    m->file = file;
    for (int i = 0; i <= 4; i++) {
        m->s_t1[i] = sfSprite_create();
        m->t_t1[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_t1[i], m->t_t1[j], sfTrue);
        sfSprite_setPosition(m->s_t1[i], (sfVector2f){-100, -200});
        j++;
    }
    return m;
}