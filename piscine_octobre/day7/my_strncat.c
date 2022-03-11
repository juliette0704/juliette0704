/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** task
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 1;

    while(dest[i] != '\0') {
        i++;
    }
    while(src[j] != '\0' && j < nb) {
    j++;
    }
    dest[j] = '\0';
    return (dest);
}
