/*
** EPITECH PROJECT, 2021
** MY SWAPSTR
** File description:
** Swaps the content of two strings
*/

#include <unistd.h>

void my_swapstr(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}
