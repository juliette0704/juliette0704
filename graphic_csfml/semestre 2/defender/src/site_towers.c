/*
** EPITECH PROJECT, 2022
** site
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

place_t *sprite_place(void)
{
    int j = 0;
    place_t *m = malloc(sizeof(place_t));
    char *file[] = {"./placement/place.jpg"
    , "./placement/place.jpg"};
    m->file = file;
    for (int i = 0; i <= 1; i++) {
        m->s_place[i] = sfSprite_create();
        m->t_place[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_place[i], m->t_place[j], sfTrue);
        j++;
    }
    sfSprite_setPosition(m->s_place[0], (sfVector2f){180, 470});
    sfSprite_setPosition(m->s_place[1], (sfVector2f){850, 600});
    return m;
}

bgtower_t *sprite_bg_tower(void)
{
    int j = 0;
    bgtower_t *m = malloc(sizeof(bgtower_t));
    char *file[] = {"./placement/place2.jpg"
    , "./placement/place2.jpg"};
    m->file = file;
    for (int i = 0; i <= 1; i++) {
        m->s_bgtower[i] = sfSprite_create();
        m->t_bgtower[j] = sfTexture_createFromFile(file[j], NULL);
        sfSprite_setTexture(m->s_bgtower[i], m->t_bgtower[j], sfTrue);
        sfSprite_setPosition(m->s_bgtower[i], (sfVector2f){1500, 500});
        j++;
    }
    return m;
}

void emplace_tower(global_t *m)
{
    sfVector2i position = sfMouse_getPositionRenderWindow(m->window);
    sfIntRect spacemente = (sfIntRect){0 , 0,100, 100};
    sfIntRect spacemente2 = (sfIntRect){180 ,470,100, 100};
    sfIntRect spacement = (sfIntRect){0, 0, 100, 100};
    sfIntRect spacement2 = (sfIntRect){850 ,600,100, 100};
    sfSprite_setTextureRect(m->place->s_place[0], spacement);
    sfSprite_setTextureRect(m->place->s_place[1], spacemente);
    if (sfIntRect_contains(&spacemente2, position.x, position.y) && m->event.type == sfEvtMouseButtonReleased) {
        m->j = 1;
        m->firstplace = 1;
    }
    if (sfIntRect_contains(&spacement2, position.x, position.y) && m->event.type == sfEvtMouseButtonReleased) {
        m->j = 1;
        m->secondplace = 1;
    }
    mouse_tower1_select(m);
    mouse_tower2_select(m);
    mouse_tower3_select(m);
}

void create_and_place_t1(global_t *m)
{
    
}
