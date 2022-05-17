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
        for (int j = 0; maze[i][j] != '\0';j++) {
            if (maze[i][j] == '<')
                maze[i][j] = '*';
            write (1, &maze[i][j], 1);
        }
        if (maze[i + 1] != NULL)
            write(1, "\n", 1);
    }
}

void size_maze(maze_t *maze)
{
    int i = 0;
    int j = 0;
    for (; maze->maze[i][j] != '\0'; j++);
    for (; maze->maze[i]; i++) {
    }
    maze->x = i;
    maze->y = j--;

}

// int verif_front(maze_t *mazet, nb_t *nb, stacktogo_t *sol)
// {
//     if (mazet->maze[nb->x][nb->y + 1] == '*') {
//         nb->y++;
//         add_element_to_stack(sol, nb, nb);
//         mazet->maze[nb->x][nb->y] = 'o';
//         return 0;
//     } else if (mazet->maze[nb->x + 1][nb->y] == '*') {
//         nb->x++;
//         add_element_to_stack(sol, nb, nb);
//         mazet->maze[nb->x][nb->y] = 'o';
//         return 0;
//     } else if (nb->x > 0 && mazet->maze[nb->x-1][nb->y] == '*') {
//             nb->x--;
//             add_element_to_stack(sol, nb, nb);
//             mazet->maze[nb->x][nb->y] = 'o';
//             return 0;
//     } else 
//             return 1;
// }

// int verif_back(maze_t *mazet, nb_t *nb, stacktogo_t *sol)
// {
//     if (mazet->maze[nb->x][nb->y-1] == '*') {
//         nb->y--;
//         add_element_to_stack(sol, nb, nb);
//         mazet->maze[nb->x][nb->y] = 'o';
//     }
//     else if (mazet->maze[nb->x-1][nb->y] == '*') {
//         nb->x--;
//         add_element_to_stack(sol, nb, nb);
//         mazet->maze[nb->x][nb->y] = 'o';
//     }
//     else if (mazet->maze[nb->x-1][nb->y] == 'o') {
//             mazet->maze[nb->x][nb->y] = '<';
//             nb->x--;
//             unstack(sol);
//     } else
//             return 1;
// }

// int verif_up(maze_t *mazet, nb_t *nb, stacktogo_t *sol)
// {
//     if (mazet->maze[nb->x+1][nb->y] == 'o') {
//         mazet->maze[nb->x][nb->y] = '<';
//         nb->x++;
//         unstack(sol);
//         return 0;
//     }
//     else if (mazet->maze[nb->x][nb->y-1] == 'o') {
//         mazet->maze[nb->x][nb->y] = '<';
//         nb->y--;
//         unstack(sol);
//         return 0;
//     }
//     else if (mazet->maze[nb->x][nb->y+1] == 'o') {
//             mazet->maze[nb->x][nb->y] = '<';
//             nb->y++;
//             unstack(sol);
//             return 0;
//     } else 
//             return 1;
// }

void loop_solver(nb_t *nb, maze_t *mazet, stacktogo_t *sol)
{
    if (nb->x < mazet->x -1) {
        if (verif_front(mazet, nb, sol) == 1) {
            if (verif_back(mazet, nb, sol) == 1)
                verif_up(mazet, nb, sol);
        }
    }
    else if (mazet->maze[nb->x-1][nb->y] == 'o') {
        mazet->maze[nb->x][nb->y] = '<';
        nb->x--;
        unstack(sol);
    }
}

int solver(char *maz)
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
    if (mazet->maze[0][0] != '*') return 1;
    if (mazet->maze[mazet->x - 1][mazet->y - 1] != '*') return 1;
    mazet->maze[nb->x][nb->y] = 'o';
    while (1) {
        if (nb->x >= mazet->x - 1 && nb->y >= mazet->y - 1)
            break;
        loop_solver(nb, mazet, sol);
    }
    print_tab(mazet->maze);
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
    if (solver(max) == 1)
        return 84;
    return 0;
}

int main(int ac , char **av)
{
    if (open_read(av) == 84)
        return 84;
    return 0;
}
