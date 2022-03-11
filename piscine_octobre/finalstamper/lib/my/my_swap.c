/*
** EPITECH PROJECT, 2021
** MY SWAP
** File description:
** Swaps the content of two integers
*/

#include <unistd.h>

void my_swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
