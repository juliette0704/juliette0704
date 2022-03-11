/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** task
*/
#include "my_putchar.c"

int power(int a, int b)
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

int count_digits(int nb)
{
    int count = 0;
    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar(45);
    }
    for (int i = count_digits(nb); i > 0; i--) {
        my_putchar((nb / power(10, i - 1) % 10) + 48);
    }
    return(0);
}
