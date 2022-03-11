/*
** EPITECH PROJECT, 2021
** count_digitslong.c
** File description:
** task
*/

long long count_digitslong(long long nb)
{
    long long count = 0;
    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}