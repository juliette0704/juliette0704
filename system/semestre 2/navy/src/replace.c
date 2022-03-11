/*
** EPITECH PROJECT, 2021
** replace.c
** File description:
** navy
*/

#include "my.h"

void creat_boat(char size, char firstland[2], int horizontal, char **mytab)
{
    int c = 0;
    int l = 0;
    c = firstland[0] - 49;
    l = firstland[1] - 49;
    if ((c && l >= 0) && (c && l < 9)) {
        int y = 0;
        int x = 0;
        for (int i = 0; i < size; i++) {
            if (horizontal == 1)
                mytab[l][c+i] = size;
            else
                mytab[l+i][c] = size;
        }
    }
}

void analyse_pos(char tab[4][7], char **mytab)
{
    char sizeboat;
    char firstland[2];
    char lastland[2];
    int x = 0, y = 0, test = 0;
    while (tab[y][x] != '\0') {
        int horizontal = 0;
        sizeboat = tab[y][0] - 48;
        firstland[0] = (tab[y][2]) - 16;
        firstland[1] = tab[y][3];
        lastland[0] = (tab[y][5]) - 16;
        lastland[1] = tab[y][6];
        if (firstland[1] == lastland[1])
            horizontal = 1;
        if (((lastland[0] && lastland[1]) > 0) && ((lastland[0] && lastland[1]) <= 8))
            creat_boat(sizeboat, firstland, horizontal, mytab);
        tab[y++];
        }
    my_putstr("my positions:\n");
    print_square(mytab);
    my_putchar('\n');
}

void array_pos(char *pos, char **mytab)
{
    char tab[4][7];
    int x = 0;
    int y = 0;
    int i = 0;
    int yes = 0, yes2 = 0;
    while (y < 4) {
        while (x < 8) {
            tab[y][x] = pos[i];
            x++;
            i++;
        }
        x = 0;
        tab[y++];
    }
    analyse_pos(tab, mytab);
}

char **initial_tab(char *pos, char **mytab, char **enemytab)
{
    int y = 0;
    int x = 0;
    int j = 0;
    while (y < 8) {
        while (x < 8) {
            mytab[y][x] = '.';
            x++;
        }
        y++;
        x = 0;
    }
    array_pos(pos, mytab);
    my_putstr("enemy’s positions:\n");
    create_square(enemytab);
    return mytab;
}