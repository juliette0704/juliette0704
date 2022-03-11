/*
** EPITECH PROJECT, 2021
** replace.c
** File description:
** navy
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "my.h"
#include <stdlib.h>

int verify_touch(int col, int line, char **map)
{
    int life = 0;
    int where = 0;
    where = map[line - 1][col - 1];
    if (where == 'o' || where == 'x')
        return 0;
    if (where == '.')
        return 0;
    else
        return 1;
}