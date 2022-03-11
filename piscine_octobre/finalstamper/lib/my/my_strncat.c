/*
** EPITECH PROJECT, 2021
** MY STRNCAT
** File description:
** Not coded yet
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int destlen = my_strlen(dest);
    int srclen = my_strlen(src);
    int i;
    for (i = 0; i < nb && i < srclen; i++) {
        dest[destlen + i] = src[i];
    }
    dest[destlen + i] = '\0';
    return (dest);
}
