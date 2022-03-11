/*
** EPITECH PROJECT, 2021
** my_strupcase.c
** File description:
** task
*/

#include "my_putstr.c"

char *my_strupcase(char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
    }
    my_putstr(str);
    return (str);
}
