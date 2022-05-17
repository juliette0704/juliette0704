/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

void print_grid(all_t *glo)
{
    for (int i = 0; i < glo->lar; i++) {
        for (int j = 0; j < glo->lon; j++) {
            if (glo->grid[i][j] != NULL) {
                init_pair(glo->grid[i][j]->color, glo->grid[i][j]->color, COLOR_BLACK);
                attron(COLOR_PAIR(glo->grid[i][j]->color));
                mvprintw(i, j + 1, "*");
                attroff(COLOR_PAIR(glo->grid[i][j]->color));
                
            }
        }
    }
    refresh();
}

void reset_grid(all_t *glo)
{
    family_t *fam = glo->current;
    cell_t ***grid = glo->grid;
    for (int i = 0; fam->kids[i] != NULL; i++) {
        grid[fam->kids[i]->y][fam->kids[i]->x] = NULL;
    }
}

void gravite(all_t *glo)
{
    double total = (clock() - glo->cloc) / (10000 + 10000 / glo->sco->level);
    if (total > 1) {
        for (int i = 0; glo->current->kids[i] != NULL; i++) {
            glo->current->kids[i]->y += 1;
        }
        glo->cloc = clock();
    }
}

void move_bot(all_t *glo)
{
    reset_grid(glo);
    for (int i = 0; glo->current->kids[i] != NULL; i++) {
        glo->current->kids[i]->y += 1;
    }
}

void move_current(all_t *glo, char c)
{
    reset_grid(glo);
    gravite(glo);
    for (int i = 0; glo->current->kids[i] != NULL; i++) {
        glo->grid[glo->current->kids[i]->y][glo->current->kids[i]->x] = glo->current->kids[i];
    }
    if (c == 'D')
        move_left(glo);
    if (c == 'C')
        move_right(glo);
    if (cant_move_bot(glo))
        glo->current = NULL;
    if (c == 'B')
        move_bot(glo);
    if (c == 'q') {
        endwin();
        exit(0);
    }
    if (c == 'p')
        pause_game(glo);
}