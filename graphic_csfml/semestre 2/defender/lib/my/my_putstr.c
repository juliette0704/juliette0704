/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** task
*/

#include <unistd.h>

int my_strlen(char *str)
{
    int i = 0;

    for ( ; str[i] != '\0' ; i++);
    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
