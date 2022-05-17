/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

void create_mini_tab(nb_t *nb)
{
    char *clemm = malloc(sizeof(char) * my_strlen(nb->tetrim));
    int nbr = 0;
    int zero = 0;
    while (nb->tetrim[nbr] != '\n')
        nbr++;
    while (nb->tetrim[nbr] != '\0') {
        clemm[zero] = nb->tetrim[nbr];
        zero++;
        nbr++;
    }
    nb->tetrim = clemm;
}

nb_t *unstack(struct stacktogo *stackToDepile)
{
    nb_t *nb = malloc(sizeof(nb_t));
    elmtogo_t *elementDepile = stackToDepile->first;

    if (stackToDepile != NULL && stackToDepile->first != NULL) {
        nb->tetris = elementDepile->x;
        stackToDepile->first = elementDepile->next;
        free(elementDepile);
        return nb;
    }
    return 0;
}

char *read_file(char *av)
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
    printf(max);
    return max;
}

void help_mode()
{
    read_file("help.txt");
}