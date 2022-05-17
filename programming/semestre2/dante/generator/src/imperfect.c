/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** dante
*/

#include "my.h"
#include "generator.h"
#include <string.h>

void imperfect_maze(maze_t *maze)
{
    nb_t *nb = malloc(sizeof(nb_t));
    nb->x = 0;
    nb->y = 0;
    time_t t;
    int i = 1;
    stacktogo_t *stackv = malloc(sizeof(stacktogo_t));
    stacktogo_t *stackway = malloc(sizeof(stacktogo_t));
    add_element_to_stack(stackv, nb, nb);
    srand((unsigned) time(&t));
    int no = 0;
    maze->maze[0][0] = '*';
    maze->maze[maze->x - 1][maze->y - 1] = '*';
    maze->maze[maze->x - 2][maze->y - 1] = '*';
    maze->maze[maze->x - 1][maze->y - 2] = '*';
    loop_maze1(nb, stackv, maze);
    // print_square(maze);
}
