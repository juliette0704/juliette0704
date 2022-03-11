/*
** EPITECH PROJECT, 2021
** MY STRCAT
** File description:
** Concarteates 2 strings
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int destlen = my_strlen(dest);
    int srclen = my_strlen(src);
    int i;
    for (i = 0; i < srclen; i++) {
        dest[destlen + i] = src[i];
    }
    dest[destlen + i] = '\0';
    return (dest);
}
