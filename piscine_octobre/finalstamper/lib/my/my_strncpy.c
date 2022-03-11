/*
** EPITECH PROJECT, 2021
** MY STRNCPY
** File description:
** Copies a string into another
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int srclen = my_strlen(src);
    while (i < n) {
        if (i > srclen) {
            dest[i] = '\0';
        } else {
            dest[i] = src[i];
        }
        i++;
    }
    return (dest);
}
