/*
** EPITECH PROJECT, 2021
** my_put_unsigned.c
** File description:
** my_put_unsigned
*/

#include <stdarg.h>

void my_putchar(char c);
long long count_digitslong(long long nb);
long long powerlong(int a, int b);

void my_put_unsigned(va_list nb1)
{
    long long nb = va_arg(nb1, long long);

    if (nb == 0) {
        my_putchar('0');
        return ;
    }
    if (nb < 0) {
        nb *= -1;
        nb = nb - 4294967296;
        return ;
    }
    for (int i = count_digitslong(nb); i > 0; i--) {
        my_putchar((nb / powerlong(10, i - 1) % 10) + 48);
    }
}