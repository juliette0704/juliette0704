/*
** EPITECH PROJECT, 2021
** check_sol.c
** File description:
** antman
*/

#include "my.h"
#include "solver.h"


int verif_front(maze_t *mazet, nb_t *nb, stacktogo_t *sol)
{
    if (mazet->maze[nb->x][nb->y + 1] == '*') {
        nb->y++;
        add_element_to_stack(sol, nb, nb);
        mazet->maze[nb->x][nb->y] = 'o';
        return 0;
    } else if (mazet->maze[nb->x + 1][nb->y] == '*') {
        nb->x++;
        add_element_to_stack(sol, nb, nb);
        mazet->maze[nb->x][nb->y] = 'o';
        return 0;
    } else if (nb->x > 0 && mazet->maze[nb->x-1][nb->y] == '*') {
            nb->x--;
            add_element_to_stack(sol, nb, nb);
            mazet->maze[nb->x][nb->y] = 'o';
            return 0;
    } else 
            return 1;
}

int verif_back(maze_t *mazet, nb_t *nb, stacktogo_t *sol)
{
    if (mazet->maze[nb->x][nb->y-1] == '*') {
        nb->y--;
        add_element_to_stack(sol, nb, nb);
        mazet->maze[nb->x][nb->y] = 'o';
    }
    else if (mazet->maze[nb->x-1][nb->y] == '*') {
        nb->x--;
        add_element_to_stack(sol, nb, nb);
        mazet->maze[nb->x][nb->y] = 'o';
    }
    else if (mazet->maze[nb->x-1][nb->y] == 'o') {
            mazet->maze[nb->x][nb->y] = '<';
            nb->x--;
            unstack(sol);
    } else
            return 1;
}

int verif_up(maze_t *mazet, nb_t *nb, stacktogo_t *sol)
{
    if (mazet->maze[nb->x+1][nb->y] == 'o') {
        mazet->maze[nb->x][nb->y] = '<';
        nb->x++;
        unstack(sol);
        return 0;
    }
    else if (mazet->maze[nb->x][nb->y-1] == 'o') {
        mazet->maze[nb->x][nb->y] = '<';
        nb->y--;
        unstack(sol);
        return 0;
    }
    else if (mazet->maze[nb->x][nb->y+1] == 'o') {
            mazet->maze[nb->x][nb->y] = '<';
            nb->y++;
            unstack(sol);
            return 0;
    } else 
            return 1;
}