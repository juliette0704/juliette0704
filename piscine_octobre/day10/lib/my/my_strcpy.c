/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** task
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;
    while(dest[i] < '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i++] = '\0';
    return(src);
}
