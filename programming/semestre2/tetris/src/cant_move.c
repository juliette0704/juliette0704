/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

int cant_move_bot(all_t *glo)
{
    family_t *fam = glo->current;
    cell_t *ce;
    for (int i = 0; fam->kids[i] != NULL; i++) {
        if (fam->kids[i]->y + 1 > glo->lar - 1)
            return 1;
        ce = fam->kids[i];
        if (glo->grid[ce->y + 1][ce->x] != NULL &&
                            glo->grid[ce->y + 1][ce->x]->parent != ce->parent)
            return 1;
    }
    return 0;
}

int cant_move_left(all_t *glo)
{
    family_t *fam = glo->current;
    cell_t *ce;
    for (int i = 0; fam->kids[i] != NULL; i++) {
        if (fam->kids[i]->x - 1 < 0)
            return 1;
        ce = fam->kids[i];
        if (glo->grid[ce->y][ce->x - 1] != NULL &&
                            glo->grid[ce->y][ce->x - 1]->parent != ce->parent)
            return 1;
    }
    return 0;
}

int cant_move_right(all_t *glo)
{
    family_t *fam = glo->current;
    cell_t *ce;
    for (int i = 0; fam->kids[i] != NULL; i++) {
        if (fam->kids[i]->x + 1 > glo->lon - 1)
            return 1;
        ce = fam->kids[i];
        if (glo->grid[ce->y][ce->x + 1] != NULL &&
                            glo->grid[ce->y][ce->x + 1]->parent != ce->parent)
            return 1;
    }
    return 0;
}

void move_left(all_t *glo)
{
    if (cant_move_left(glo))
        return;
    reset_grid(glo);
    for (int i = 0; glo->current->kids[i] != NULL; i++) {
        glo->current->kids[i]->x -= 1;
    }
}

void move_right(all_t *glo)
{
    if (cant_move_right(glo))
        return;
    reset_grid(glo);
    for (int i = 0; glo->current->kids[i] != NULL; i++) {
        glo->current->kids[i]->x += 1;
    }
}