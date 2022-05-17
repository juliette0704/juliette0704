/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

char *my_str_catbis(char *stra, char* strb)
{
    int i = 0;
    char *re = malloc(sizeof(char) * (my_strlen(stra) + my_strlen(strb) + 1));
    for (i; stra[i] != 0; i++) {
        re[i] = stra[i];
    }
    for (int j = 0; strb[j] != 0; j++) 
        re[j + i] = strb[j];
    return re;
}

char *choose_random(all_t *glo)
{
    time_t t;
    int random = 0;
    srand((unsigned) time(&t));
    random = rand() % tab_len(glo->file_na);
    return(read_map(my_str_catbis("./tetriminos/", glo->file_na[random])));
}

#define DELAY 10000

void create_map(map_t *map)
{
    int x = 22;
    int y = 27;
    map->map = (char**)malloc((x*y) * sizeof(char*));
    map->y = 22;
    map->x = 27;
    for (int i = 0; i < map->x; i++) {
        map->map[i] = malloc(sizeof(char) * map->y + 1);
        for (int j = 0; j < map->y; j++) {
            if (i == 0 || i == y - 1)
                map->map[i][j] = '-';
             else if (j == 0 || j == x - 1)
                map->map[i][j] = '|';
            else map->map[i][j] = ' ';
        }
        map->map[i][map->y] = '\0';
    }
    map->map[map->x] = NULL;
}

void check_size(int j, int i, all_t *g)
{
    if (g->file[j][i] != ' ') {
        if (i == 0) {
            g->num->sizex = g->file[j][i];
        }
        else if (i == 2)
            g->num->sizey = g->file[j][i];
        else
            g->num->color = g->file[j][i];
    }
}

int clement(char **file_tab, int j, int i, nb_t *nb, int yes)
{
    if (!(file_tab[0][i] >= 48 && file_tab[0][i] <= 57)) {
        if (file_tab[0][i] != ' ') {
            nb->no = 1;
            yes = 1;
        } else {
            if (file_tab[j][i] != ' ') {
                if (i == 0)
                    nb->sizex = file_tab[j][i];
                else if (i == 2)
                    nb->sizey = file_tab[j][i];
                else
                    nb->color = file_tab[j][i];
            }
        }
    }
    return yes;
}