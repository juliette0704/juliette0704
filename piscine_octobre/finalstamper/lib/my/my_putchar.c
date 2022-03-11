/*
** EPITECH PROJECT, 2021
** MY PUTCHAR
** File description:
** Displays a char
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
