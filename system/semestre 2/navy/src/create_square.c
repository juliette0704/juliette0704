/*
** EPITECH PROJECT, 2021
** create_square.c
** File description:
** square
*/

#include "my.h"

void beta_line(void)
{
    char beta[18] = "-+---------------";
    my_putstr(beta);
    my_putchar('\n');
}

void alpha_line(void)
{
    char line[15];
    int x = 2;
    int y = 0;
    char ascii = 'A';
    line[0] = ' ';
    line[1] = '|';
    while (x < 15) {
        line[x] = ascii;
        x++;
        line[x] = ' ';
        x++;
        ascii++;
    }
    line[x] = ascii;
    line[x++] = ascii++;
    my_putstr(line);
    my_putstr("\n");
}

void print_square(char **tab)
{
    alpha_line();
    beta_line();
    int y = 0;
    int x = 0;
    while (y < 8) {
    my_put_nbr(y + 1);
    my_putchar('|');
        while (x < 8) {
            if (tab[y][x] == 120 || tab[y][x] == 111)
                my_putchar(tab[y][x]);
            if (tab[y][x] == '.')
                my_putchar(tab[y][x]);
            if (tab[y][x] <= 8 && tab[y][x] > 0)
                my_put_nbr(tab[y][x]);
            my_putchar(' ');
            x++;
        }
    my_putstr("\n");
    y++;
    x = 0;
    }
}

char **create_square(char **tab)
{
    int y = 0;
    int x = 0;
    int j = 0;
    while (y < 8) {
        while (x < 8) {
            tab[y][x] = '.';
            x++;
        }
        y++;
        x = 0;
    }
    print_square(tab);
    my_putchar('\n');
    return tab;
}