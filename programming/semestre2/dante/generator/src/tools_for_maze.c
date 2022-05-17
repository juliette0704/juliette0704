/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** dante
*/

#include "my.h"
#include "generator.h"
#include <string.h>

maze_t *print_square(maze_t *maze)
{
    int y = 0;
    int x = 0;
    int the = 0;
    while (y < maze->y) {
        my_putstr(maze->maze[y]);
        if (y < maze->y - 1)
            my_putchar('\n');
        y++;
    }
}

maze_t *create_square(maze_t *maze)
{
    int y = 0;
    int x = 0;
    while (y < maze->y) {
        while (x < maze->x) {
            maze->maze[y][x] = 'X';
            x++;
        }
        y++;
        x = 0;
    }
    my_putchar('\n');
    return maze;
}
