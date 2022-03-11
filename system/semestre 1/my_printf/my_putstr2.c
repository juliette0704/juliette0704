/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task
*/

#include <stdarg.h>
#include <unistd.h>

int my_strlen(char const *str);

void my_putstr2(va_list str1)
{
    char *str = va_arg(str1, char *);

    write(1, str, my_strlen(str));
}