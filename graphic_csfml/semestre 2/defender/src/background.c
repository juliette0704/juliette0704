/*
** EPITECH PROJECT, 2022
** background
** File description:
** defender
*/

#include "my.h"
#include "defender.h"
#include <math.h>

bg_t *sprite_bg(void)
{
    bg_t *background = malloc(sizeof(bg_t));
    char *file[] = {"./background/bg.png"};
    background->file = file;
    background->s_bg[0] = sfSprite_create();
    background->t_bg[0] = sfTexture_createFromFile(file[0], NULL);
    sfSprite_setTexture(background->s_bg[0], background->t_bg[0], sfTrue);
    sfSprite_setPosition(background->s_bg[0], (sfVector2f){0, 0});
    return background;
}