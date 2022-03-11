/*
** EPITECH PROJECT, 2021
** my_put_nbr2.c
** File description:
** task
*/

#include <stdarg.h>
#include <unistd.h>

void my_putchar(char c);

int power2(int a, int b)
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

int count_digits2(int nb)
{
    int count = 0;
    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}

void my_put_nbr2(va_list nb1)
{
    int nb = va_arg(nb1, int);

    if (nb == 0) {
        my_putchar('0');
        return ;
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    for (int i = count_digits2(nb); i > 0; i--) {
        my_putchar((nb / power2(10, i - 1) % 10) + 48);
    }
}