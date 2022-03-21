/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** dante
*/

#include "my.h"
#include "generator.h"

void print_tab(char **maze);

maze_t *print_square(maze_t *maze)
{
    int y = 0;
    int x = 0;
    int the = 0;
    while (y < maze->y) {
        // for (int i = 0; i < maze->x; i++) {
            my_putstr(maze->maze[y]);
        // }
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
    // print_square(maze);
    my_putchar('\n');
    return maze;
}

int is_it_visited(struct stacktogo *stackv, int xtofind, int ytofind)
{
    stacktogo_t *tmp = stackv;
    while (tmp->first != NULL) {
        if (tmp->first->next != NULL) {
            if (tmp->first->x == xtofind && tmp->first->y == ytofind)
                return 1;
        }
        tmp->first = tmp->first->next;

    }
    // for (int i = 0; i < 50; i++) {
    //     if (tmp->first->x == xtofind && tmp->first->y == ytofind) {
    //         printf("trouvé");
    //         return 1;
    //     }
    //     tmp->first = tmp->first->next;
    // }
    return 0;
}


void imperfect_maze(maze_t *maze)
{
    nb_t *nb = malloc(sizeof(nb_t));
    int random = 0;
    nb->x = 0;
    nb->y = 0;
    time_t t;
    int i = 1;
    stacktogo_t *stackv = malloc(sizeof(stacktogo_t));
    stacktogo_t *stackway = malloc(sizeof(stacktogo_t));
    srand((unsigned) time(&t));
    int end = 0;
    while (1) {
        if (nb->y == maze->y - 1 && nb->x == maze->x - 1) {
            break;
        }
        random = rand() % 4 + 1;
        switch (random) {
            case 1 :
            if (nb->x >= 0 && (nb->x <= maze->x -2)) {
                nb->x += 1;
                add_element_to_stack(stackv, nb, nb);
            }
            break;
            case 2 :
            if ((nb->x <= maze->x -1) && nb->x > 0) {
                nb->x -= 1;
                add_element_to_stack(stackv, nb, nb);
            }
            break;
            case 3 :
            if (nb->y >= 0 && (nb->y < maze->y -1)) {
                nb->y += 1;
                add_element_to_stack(stackv, nb, nb);
            }
            break;
            case 4 :
            if (nb->y < maze->y -1 && nb->y > 0) {
                nb->y -= 1;
                add_element_to_stack(stackv, nb, nb);
            }
            break;
        }
    }
    while (stackv->first != NULL) {
        if (stackv->first->x < maze->x && stackv->first->y < maze->y)
            maze->maze[stackv->first->x][stackv->first->y] = '.';
        unstack(stackv);
    }
    maze->maze[0][0] = '.';
    print_tab(maze->maze);
}

void perfect_maze(int x, int y)
{

}

void print_tab(char **maze)
{
    for (int i = 0; maze[i]; i++) {
        my_putstr(maze[i]);
        my_putchar('\n');
    }
}

void init_maze(int x, int y)
{
    maze_t *maze = malloc(sizeof(maze_t));
    maze->x = x;
    maze->y = y;
    int i = 0;
    maze->maze = (char**)malloc((x*y) * sizeof(char*));
    for (int i = 0; i < maze->x; i++) {
        maze->maze[i] = malloc(sizeof(char) * maze->y + 1);
        for (int j = 0; j < maze->y; j++)
            maze->maze[i][j] = 'X';
        maze->maze[i][maze->y] = '\0';
    }
    maze->maze[maze->x] = NULL;
    //if is a perfect square :
    imperfect_maze(maze);
}

int main(int ac , char **av)
{
    // nb_t *nb = malloc(sizeof(nb_t));
    // stacktogo_t *togo = malloc(sizeof(stacktogo_t));
    init_maze(10, 10);
}
 
