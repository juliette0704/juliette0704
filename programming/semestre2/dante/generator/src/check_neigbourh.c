/*
** EPITECH PROJECT, 2021
** check_neigbourh.c
** File description:
** neigbourg
*/

#include "my.h"
#include "generator.h"
#include <string.h>

void for_down1(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->x < maze->x - 2 &&  maze->maze[nb->x + 2][nb->y] == 'X') {
        nb->x++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->x++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}

void for_down(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->x < maze->x - 2 &&  maze->maze[nb->x + 2][nb->y] == 'X') {
        nb->x++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->x++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}

void for_up1(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->x > 1 && maze->maze[nb->x - 2][nb->y] == 'X') {
        nb->x--;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->x--;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}

void for_up(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->x > 1 && maze->maze[nb->x - 2][nb->y] == 'X') {
        nb->x--;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->x--;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}

void for_right1(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->y >= 2 && maze->maze[nb->x][nb->y - 2] == 'X') {
        nb->y -= 1;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->y -= 1;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}


void for_right(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->y >= 2 && maze->maze[nb->x][nb->y - 2] == 'X') {
        nb->y -= 1;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->y -= 1;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}

void for_left1(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->y < maze->y - 1 &&  maze->maze[nb->x][nb->y + 2] == 'X') {
        nb->y++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->y++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}

void for_left(nb_t *nb, maze_t *maze, stacktogo_t *stackv)
{
    if (nb->y < maze->y - 1 &&  maze->maze[nb->x][nb->y + 2] == 'X') {
        nb->y++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
        nb->y++;
        add_element_to_stack(stackv, nb, nb);
        maze->maze[nb->x][nb->y] = '*';
    }
}
