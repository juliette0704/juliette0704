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
    int ss = my_strlen(src);
    int sd = my_strlen(dest);
    int temp = sd;

    while(temp <= ss) {
		dest[temp] = src[i];
        i++;
        temp++;
    }
    dest[temp] = '\0';
    return (dest);
}
