/*
** EPITECH PROJECT, 2021
** my_itoa
** File description:
** bistro
*/

#include "my.h"
#include <stdlib.h>

char *my_int_to_str(int digits)
{
    int	len;
    char *str;
    int temp;

    temp = digits;
    len = 0;
    while (temp > 0) {
        temp /= 10;
        len++;
    }
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    while (len--) {
        str[len] = digits % 10  + '0';
        digits /= 10;
    }
    return (str);
}
