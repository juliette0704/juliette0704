/*
** EPITECH PROJECT, 2021
** my_strlowcase.c
** File description:
** task
*/

#include "my_putstr.c"

char *my_strlowcase(char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
    }
    my_putstr(str);
    return (str);
}
