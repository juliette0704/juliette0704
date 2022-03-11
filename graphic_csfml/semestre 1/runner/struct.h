/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** my
*/


#ifndef STRUCT_H_
    #define STRUCT_H_
    
    #include "my.h"

typedef struct jump
{
    int x;
    int y;
} jump_t;

typedef struct moovrect
{
    sfIntRect texturerect;
} moovrect_t;

typedef struct turtle
{
    sfSprite *s_turtle[20];
    sfTexture *t_turtle[20];
    char **file;
} turtle_t;

typedef struct victory
{
    sfSprite *s_vic[1];
    sfTexture *t_vic[1];
    char **file;
} victory_t;

typedef struct menu
{
    sfSprite *s_men[1];
    sfTexture *t_men[1];
    char **file;
} menu_t;

typedef struct ninja
{
    sfSprite *s_nin[1];
    sfTexture *t_nin[1];
    char **file;
} ninja_t;

typedef struct bg {
    sfSprite *s_bg[11];
    sfTexture *t_bg[6];
    char **file;
} bg_t;

typedef struct score
{
    int scores;
} score_t;

typedef struct globale
{
    sfRenderWindow *window;
    sfClock *clockbg;
    sfTime timebg;
    float secondbg;
    sfClock *clockjump;
    sfTime timejump;
    float secondjump;
    float speedjump;
    sfClock *clock;
    sfTime time;
    float second;
    float speedrect;
    sfVideoMode mode;
    sfEvent event;
    bg_t *bg;
    sfText *text;
    ninja_t *ninja;
    victory_t *vic;
    turtle_t *turtle;
    moovrect_t *moovrect;
    jump_t *jump;
    int i;
    int j;
    int count;
    int o;
    int vec;
    int menu;
    const sfIntRect rectturtle;
    sfIntRect rectninja;
    sfIntRect rectjump;
} globale_t;

typedef struct speed
{
    int speedo;
    int speedjump;
} speed_t;

#endif /* !STRUCT_H_ */
