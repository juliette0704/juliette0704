/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** dante
*/

#include "my.h"
#include "generator.h"
#include <string.h>

void print_tab(char **maze);
int is_a_neigbourg(maze_t *maze, nb_t *nb);

void switch_random1(nb_t *nb, maze_t *maze, stacktogo_t *stackv, int random)
{
    switch (random) {
        case 1 :
            for_left1(nb, maze, stackv);
        break;
        case 2 :
            for_right1(nb, maze, stackv);
        break;
        case 3 :
            for_down1(nb, maze, stackv);
        break;
        case 4 :
            for_up1(nb, maze, stackv);
        break;
    }
}

void switch_random(nb_t *nb, maze_t *maze, stacktogo_t *stackv, int random)
{
    switch (random) {
        case 1 :
            for_left(nb, maze, stackv);
        break;
        case 2 :
            for_right(nb, maze, stackv);
        break;
        case 3 :
            for_down(nb, maze, stackv);
        break;
        case 4 :
            for_up(nb, maze, stackv);
        break;
    }
}

void perfect_maze(maze_t *maze)
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
    loop_maze(nb, stackv, maze);
    if (maze->maze[maze->x - 2][maze->y - 1] == '*')
        maze->maze[maze->x - 1][maze->y - 2] = 'X';
        else maze->maze[maze->x - 1][maze->y - 2] = '*';
    print_square(maze);
}

void init_maze(int x, int y, int ac)
{
    maze_t *maze = malloc(sizeof(maze_t));
    maze->x = x;
    maze->y = y;
    int i = 0;
    int j = 0;
    maze->maze = (char**)malloc((x*y) * sizeof(char*));
    for (int i = 0; i < maze->x; i++) {
        maze->maze[i] = malloc(sizeof(char) * maze->y + 1);
        for (int j = 0; j < maze->y; j++)
            maze->maze[i][j] = 'X';
        maze->maze[i][maze->y] = '\0';
    }
    maze->maze[maze->x] = NULL;
    if (ac == 3)
        imperfect_maze(maze);
    else if (ac == 4)
        perfect_maze(maze);
}

int main(int ac, char **av)
{
    if (ac != 3 && ac != 4) {
        write(2, "ERROR\n", 5);
        return 84;
    }
    int x = char_to_int(av[1]);
    int y = char_to_int(av[2]);
    if (x == 0 && y == 0) {
        write(2, "ERROR\n", 5);
        return 84;
    }
    int i = 0;
    if (ac == 4) {
        if (strcmp(av[3], "perfect") == 0)
            init_maze(x, y, ac);
        else {
            write(2, "ERROR\n", 5);
            return 84;
        }
    }
    if (ac == 3)
        init_maze(x, y, ac);
}
