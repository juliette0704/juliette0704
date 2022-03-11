/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** task
*/

#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c )
{
    write(1, &c, 1);
}
