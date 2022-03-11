/*
** EPITECH PROJECT, 2021
** my_putchar2.c
** File description:
** my_put_char
*/

#include <stdarg.h>
#include <unistd.h>

void my_putchar2(va_list c1)
{
    int c = va_arg(c1, int);
    write(1, &c, 1);
}