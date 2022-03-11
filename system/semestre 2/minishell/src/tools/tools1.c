
/*
** EPITECH PROJECT, 2021
** cd.c
** File description:
** main
*/

#include "my.h"

int compare(char *s1, char *s2)
{
    int i = 0;
    while(s1[i] != '\0') {
        if(s1[i] == s2[i])
            i++;
        else
            return 0;
    }
    return 1;
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int ss = my_strlen(src);
    int sd = my_strlen(dest);
    int temp = sd;

    while(temp <= ss + sd) {
		dest[temp] = src[i];
        i++;
        temp++;
    }
    dest[temp] = '\0';
    return (dest);
}