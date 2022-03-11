/*
** EPITECH PROJECT, 2022
** only_int
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

int pair_or_not(char *res)
{
    int i = my_strlen(res);
    if ( i % 2 == 0)
        return 1;
    else
        return 0;
}

void my_putcstr(char *str)
{
    if (pair_or_not(str) == 1)
        pair(str);
    else
        impair(str);
    return;
}