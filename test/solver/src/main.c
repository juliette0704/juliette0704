/*
** EPITECH PROJECT, 2021
** main
** File description:
** antman
*/

#include "my.h"
#include "solver.h"

void print_tab(char **maze)
{
    for (int i = 0; maze[i]; i++) {
        my_putstr(maze[i]);
        if (maze[i + 1] != NULL)
            my_putchar('\n');
    }
}

void size_maze(maze_t *maze)
{
    int i = 0;
    int j = 0;
    for (; maze->maze[i][j] != '\0'; j++);
    for (; maze->maze[i]; i++) {
        my_putstr(maze->maze[i]);
        my_putchar('\n');
    }
    maze->x = i;
    maze->y = j--;

}

void solver(char *maz)
{
    int i = 0;
    char **maze = str_to_word_array(maz);
    stacktogo_t *sol = malloc(sizeof(stacktogo_t));
    maze_t *mazet = malloc(sizeof(maze_t));
    mazet->maze = maze;
    size_maze(mazet);
    nb_t *nb = malloc(sizeof(nb_t));
    nb->x = 0;
    nb->y = 0;
    add_element_to_stack(sol, nb, nb);
    int mod = 0;
    printf("\n%d\n", mazet->y);
    mazet->maze[nb->x][nb->y] = 'o';
    while (nb->x != mazet->x - 1) {
        if (mazet->maze[nb->x][nb->y + 1] == '*') {
            nb->y++;
            add_element_to_stack(sol, nb, nb);
            mazet->maze[nb->x][nb->y] = 'o';
        } else if (mazet->maze[nb->x][nb->y + 1] == 'X') {
            nb->x++;
            add_element_to_stack(sol, nb, nb);
            mazet->maze[nb->x][nb->y] = 'o';
        } else if (mazet->maze[nb->x + 1][nb->y] == '*') {
            nb->x++;
            add_element_to_stack(sol, nb, nb);
            mazet->maze[nb->x][nb->y] = 'o';
        }

    my_putchar('\n');
    my_putchar('\n');
    print_tab(mazet->maze);
    sleep(1);
    }
}

int open_read(char **av)
{
    struct stat buf;
    stat(av[1], &buf);
    int size = buf.st_size;
    int n = 1;
    char max[size];
    int fd = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        write(2, "ERROR", 5);
        return 84;
    }
    n = read(fd, max, size);
    max[n] = '\0';
    solver(max);
    return 0;
}

int main(int ac , char **av)
{
    open_read(av);
    return 0;
}
