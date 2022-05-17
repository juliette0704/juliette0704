/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** dante
*/

#include "my.h"
#include "generator.h"
#include <string.h>

int is_a_neigbourg1(maze_t *maze, nb_t *nb)
{
    int i = 0;
    if (nb->x > 1 && nb->x < maze->x - 2) {
        if (maze->maze[nb->x - 2][nb->y] == 'X')
            return i + 1;
        if (maze->maze[nb->x + 2][nb->y] == 'X')
            return i + 1;
    }
    if (nb->y > 1 && nb->y < maze->y - 2) {
        if (maze->maze[nb->x][nb->y + 2] == 'X')
            return i + 1;
        if (maze->maze[nb->x][nb->y - 2] == 'X')
            return i + 1;
    }
    return i;
}

int is_a_neigbourg(maze_t *maze, nb_t *nb)
{
    int i = 0;
    if (nb->x > 1 && nb->x < maze->x - 2) {
        if (maze->maze[nb->x - 2][nb->y] == 'X')
            return i + 1;
        if (maze->maze[nb->x + 2][nb->y] == 'X')
            return i + 1;
    }
    if (nb->y > 1 && nb->y < maze->y - 2) {
        if (maze->maze[nb->x][nb->y + 2] == 'X')
            return i + 1;
        if (maze->maze[nb->x][nb->y - 2] == 'X')
            return i + 1;
    }
    return i;
}

int verif_if_unstack1(stacktogo_t *stackv, nb_t *nb, maze_t *maze, int end)
{
    if (end == 1 && (is_a_neigbourg1(maze, nb) == 0)) {
        if (stackv->first->next != NULL) {
            unstack(stackv);
            nb->x = stackv->first->x;
            nb->y = stackv->first->y;
            unstack(stackv);
            nb->x = stackv->first->x;
            nb->y = stackv->first->y;
        }
    }
    return end;
}

int verif_if_unstack(stacktogo_t *stackv, nb_t *nb, maze_t *maze, int end)
{
    if (end == 1 && (is_a_neigbourg(maze, nb) == 0)) {
        if (stackv->first->next != NULL) {
            unstack(stackv);
            nb->x = stackv->first->x;
            nb->y = stackv->first->y;
            unstack(stackv);
            nb->x = stackv->first->x;
            nb->y = stackv->first->y;
        }
    }
    return end;
}

int is_it_visited(maze_t *maze, nb_t *nb, stacktogo_t *st)
{
    if (maze->maze[nb->x][nb->y] == '*')
        return 1;
    else
        return 0;
}

void look_back(nb_t *nb, maze_t *m, stacktogo_t *s)
{
    if (nb->y <= m->y - 2) {
        nb->y++;
        add_element_to_stack(s, nb, nb);
        m->maze[nb->x][nb->y] = '*';
    }
}

void look_front(nb_t *nb, maze_t *m, stacktogo_t *s)
{
    if (nb->y > 0) {
        nb->y -= 1;
        add_element_to_stack(s, nb, nb);
        m->maze[nb->x][nb->y] = '*';
    }
}

void look_down(nb_t *nb, maze_t *m, stacktogo_t *s)
{
    if (nb->x <= m->x - 2) {
        nb->x++;
        add_element_to_stack(s, nb, nb);
        m->maze[nb->x][nb->y] = '*';
    }
}

void switch_imperfect(int r, nb_t *nb, stacktogo_t *s, maze_t *m)
{
    switch (r) {
        case 1 :
        look_back(nb, m, s);
        break;
        case 2 :
        look_front(nb, m, s);
        break;
        case 3 :
        look_down(nb, m, s);
        break;
        case 4 :
        if (nb->x > 0) {
            nb->x--;
            add_element_to_stack(s, nb, nb);
            m->maze[nb->x][nb->y] = '*';
        }
        break;
    }
}

int verif_imperfect(nb_t *nb, int lo, int po)
{
    if (nb->x <= 2) {
        lo = 1;
    }
    if (nb->y <= 2) {
        po = 1;
    }
    if (po + lo == 2)
        return 1;
    return 0;
}

void loop_maze1(nb_t *nb, stacktogo_t *s, maze_t *m)
{
    int r = 0;
    static int e = 0, ju = 0, yes = 0;
    static int yes2 = 0, lo = 0;
    static int po = 0;
    while (1) {
        if (ju == 8 && nb->x == 0 && nb->y == 0) break;
        if (ju != 8) e = verif_if_unstack1(s, nb, m, e);
        r = rand() % 4 + 1;
        if (nb->x >= 1 && nb->y >= 1)
            e = 1;
        if (m->maze[m->x - 2][nb->y == m->y - 2] == '*') ju = 8;
        if (ju != 8) switch_random1(nb, m, s, r);
        if (ju == 8) { 
            switch_imperfect(r, nb, s, m);
            if (verif_imperfect(nb,lo,po) == 1)
                break;
        }
    }
    print_square(m);
}

void loop_maze(nb_t *nb, stacktogo_t *s, maze_t *m)
{
    int r = 0;
    static int e = 0;
    while (1) {
        if (e == 1 && nb->x == 0 && nb->y == 0)
            break;
        e = verif_if_unstack(s, nb, m, e);
        r = rand() % 4 + 1;
        if (nb->x >= 1 && nb->y >= 1)
            e = 1;
        
        switch_random(nb, m, s, r);
    }
}
