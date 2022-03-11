/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** task
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
