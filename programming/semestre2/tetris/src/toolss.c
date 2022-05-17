/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int ss = my_strlen(src);
    int sd = my_strlen(dest);
    int temp = sd;
    int t = ss + sd;
    while (temp< t) {
		dest[temp] = src[i];
        i++;
        temp++;
    }
    dest[temp] = '\0';
    return (dest);
}

int my_strlen4(char *s1)
{
    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }
    return (i);
}

int my_strcmp(char *s1, char *s2)
{
    my_strlen4(s1);
    my_strlen4(s2);
    int j = 0;
    if (my_strlen4(s1) > my_strlen4(s2)) {
        return 0;
    }
    if (my_strlen4(s2) > my_strlen4(s1)) {
        return 0;
    }
    if(my_strlen4(s2) == my_strlen4(s1)) {
        while(s2[j] != '\0') {
            if(s2[j] == s1[j])
                j++;
            else
                return (0);
        }
    }
    return (1);
}