/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>
#define DELAY 3000

void supp_line(all_t *glo, int y)
{
    for (int i = 0; i < glo->lon; i++) {
        glo->grid[y][i] = NULL;
    }
    for (int i = y; i > 1; i--) {
        for (int j = 0; j < glo->lon; j++) {
            glo->grid[i][j] = glo->grid[i - 1][j];
            if (glo->grid[i][j] != NULL)
                glo->grid[i][j]->y += 1;
        }
    }
}

void boucle_supp_line(all_t *glo, int y)
{
    bool boo = true;
    for (int i = 0; i < glo->lon; i++) {
        if (glo->grid[y][i] == NULL)
            boo = false;
    }
    if (boo == true) {
        supp_line(glo, y);
        glo->sco->line += 1;
        if (glo->sco->line % 5 == 0)
            glo->sco->level += 1;
    }
}

void clear_line(all_t *glo)
{
    for (int i = 0; i < glo->lar; i++) {
        boucle_supp_line(glo, i);
    }
    for (int i = 0; i < glo->lon; i++) {
        if (glo->grid[3][i] != NULL) {
            endwin();
            exit(0);
        }
    }
}

void gameloop(all_t *glo, map_t *map)
{
    char c;
    timeout(0);
    glo->next = create_family(choose_random(glo));
    glo->current = create_family(choose_random(glo));
    start_color();
    char *enlargeterm = "ENLARGED THE TERMINAL!!!!!!";
    while (1) {
        clear();
        if (LINES < map->x || COLS < map->y)
            mvprintw(LINES/2, (COLS / 2) - 22, enlargeterm);
        else {
            clear();
            c = getch();
            if (glo->current == NULL) {
                write(1, "oui", 3);
                clear_line(glo);
                change_current(glo);
            }
            move_print_sleep(glo, c);
        }
        usleep(DELAY);
        refresh();
    }
}

void launch_game(int ac, char **av)
{
    int x = 22;
    int y = 27;
    char enlargeterm[30] = "ENLARGED THE TERMINAL";
    
    map_t *map = malloc(sizeof(map_t));
    create_map(map);
    all_t *glo = create_glo();
    glo->win = initscr();
    glo->sco = create_score();
    for_clem(glo);
    pieces_t *piece = malloc(sizeof(pieces_t));
    piece->x = 0;
    piece->y = 0;
    int k = 0;
    glo->map = map;
    initscr();
    noecho();
    curs_set(FALSE);
    gameloop(glo, map);
}