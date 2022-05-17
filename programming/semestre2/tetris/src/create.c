/*
** EPITECH PROJECT, 2021
** create.c
** File description:
** cretae
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

cell_t ***create_grid(int lon, int lar)
{
    cell_t ***grid = malloc(sizeof(cell_t **) * lar + 1);
    for (int i = 0; i < lar; i++)
        grid[i] = malloc(sizeof(cell_t *) * lon + 1);
    for (int i = 0; i < lar; i++) {
        for (int j = 0; j < lon; j++) {
            grid[i][j] = NULL;
        }
    }
    return grid;
}


all_t *create_glo(void)
{
    all_t *glo = malloc(sizeof(all_t));
    glo->lar = 26;
    glo->lon = 20;
    glo->grid = create_grid(glo->lon, glo->lar);
    glo->current = NULL;
    for (int i = 0; i < glo->lar; i++) {
        for (int j = 0; j < glo->lon; j++)
            glo->grid[i][j] = NULL;
    }
    glo->cloc = clock();
    return glo;
}

cell_t *create_cell(int x, int y, int color, family_t *family)
{
    cell_t *ce = malloc(sizeof(cell_t));
    ce->x = x;
    ce->y = y;
    ce->color = color;
    ce->parent = family;
    return ce;
}

family_t *create_family(char *str)
{
    int x = 8;
    int y = 0;
    int index = 0;
    family_t *family= malloc(sizeof(family_t));
    family->kids = malloc(sizeof(cell_t*) * 15 * 15);
    int color = str[4] - '0';
    for(int i = 0; i < str[0]; i++) {
        if (str[i] == '*') {
            family->kids[index] = create_cell(x, y, color, family);
            index++;
        }
        if (str[i] == '\n') {
            y++;
            x = 10;
        }
        else
            x++;
    }
    family->kids[index] = NULL;
    return family;
}

score_t *create_score(void)
{
    score_t *sco = malloc(sizeof(score_t));
    sco->level = 1;
    sco->score = 0;
    sco->line = 0;
    sco->timer = 0;
    return sco;
}