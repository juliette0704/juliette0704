/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

char *my_strcopy(char *str)
{
    char *clem = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; i < my_strlen(str); i++) {
        clem[i] = str[i];
    }
    return clem;
}

void add_element_to_stack(stacktogo_t *thestack, nb_t *newx)
{
    struct elmtogo *new = malloc(sizeof(elmtogo_t));
    new->x = newx->tetris;
    new->sizex = newx->sizex;
    new->sizey = newx->sizey;
    new->color = newx->color;
    new->no = newx->no;
    new->next = thestack->first;
    new->tetrim = newx->tetrim;
    new->nboftetrim = newx->nboftetrim;
    thestack->first = new;
}

void print_double_array(char **array, int nbcol, int line)
{
    int j = 0;
    for (int i = 0; i < line; i++) {
        printw("%s", array[i]);
        j++;
        if (j < nbcol)
            printw("\n");
    }
    refresh();
}

char *read_map(char *av)
{
    static int t = 0;
    struct stat buf;
    stat(av, &buf);
    int size = buf.st_size;
    int n = 1;
    char *max = malloc(size + 1* sizeof(char));
    int fd = 0;
    fd = open(av, O_RDONLY);
    n = read(fd, max, size);
    max[n] = '\0';
    close(fd);
    t++;
    return max;
}