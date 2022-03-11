/*
** EPITECH PROJECT, 2021
** powerlong.c
** File description:
** task
*/

long long powerlong(int a, int b)
{
    int result = a;

    if (b == 0) {
        return (1);
    }
    for (int i = 0; i < b - 1; i++) {
        result *= a;
    }
    return (result);
}