/*
** EPITECH PROJECT, 2021
** MY STRCPY
** File description:
** Copies a string into another
*/

#include <unistd.h>

int my_strlen(char const *c);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    int srclen = my_strlen(src);
    int destlen = my_strlen(dest);
    for (i = 0; i < destlen || i < srclen; i++) {
        if (i <= srclen) {
            dest[i] = src[i];
        } else {
            dest[i] = '\0';
        }
    }
    return (dest);
}
