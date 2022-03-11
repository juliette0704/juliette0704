/*
** EPITECH PROJECT, 2021
** tools_for_map.c
** File description:
** tools
*/

#include "my.h"
#include "soko.h"

int sizecol(char *str)
{
    col_t *nbcol = malloc(sizeof(col_t));
    nbcol->colonmax = 0;
    int i = 0;
    int size = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            if (size > nbcol->colonmax)
                nbcol->colonmax = size;
            size = 0;
        }
        size++;
        i++;
    }
    return nbcol->colonmax;
}

int sizeline(char *str)
{
    int lines = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            lines++;
    }
    return (lines + 1);
}