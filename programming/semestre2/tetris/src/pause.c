/*
** EPITECH PROJECT, 2021
** pause.c
** File description:
** pause the game
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

void pause_game(all_t *glo)
{
    print_double_array(glo->map->map, glo->map->x, glo->map->x);
    print_grid(glo);
    print_next(glo);
    print_score(glo);
    char c = 0;
    while (c != 'p')
        c = getch();
        if (c == 'q'){
            endwin();
            exit(0);
        }
}

void change_current(all_t *glo)
{
    glo->sco->score += 1;
    glo->current = glo->next;
    glo->next = create_family(choose_random(glo));
}

void print_next(all_t *glo)
{
    cell_t *ce;
    mvprintw(0, 23, "next:");
    for (int i = 0; glo->next->kids[i] != NULL; i++) {
        ce =  glo->next->kids[i];
        init_pair(25, ce->color, COLOR_BLACK);
        attron(COLOR_PAIR(25));
        mvprintw(0 + ce->y, 20 + ce->x, "*");
        attroff(COLOR_PAIR(25));
        
    }
    refresh();
}

void print_score(all_t *glo)
{
    mvprintw(6, 24, "score: %d", glo->sco->score);
    mvprintw(7, 24, "line: %d", glo->sco->line);
    mvprintw(8, 24, "level: %d", glo->sco->level);
    mvprintw(9, 24, "timer: %d", clock() / 60000);
    refresh();
}

void move_print_sleep(all_t *glo, char c)
{
    move_current(glo, c);
    print_double_array(glo->map->map, 27, 27);
    print_grid(glo);
    print_next(glo);
    print_score(glo);
    refresh();
    usleep(6000);
}