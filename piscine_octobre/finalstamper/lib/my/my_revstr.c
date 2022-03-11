/*
** EPITECH PROJECT, 2021
** MY REVSTR
** File description:
** Reverses a string
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int srclen = my_strlen(str);
    int i, temp;
    for (i = 0; i < srclen / 2; i++) {
        temp = str[i];
        str[i] = str[srclen - i - 1];
        str[srclen - i - 1] = temp;
    }
    return (str);
}
