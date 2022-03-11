/*
** EPITECH PROJECT, 2021
** no_space.c
** File description:
** space
*/

#include "my.h"

char *delete_space(char *res)
{
    int i = 0;
    char *newres = (char*)malloc(my_strlen(res) * sizeof(char*));
    int space = 0;
    int no = 0;
    int j = 0;
    while (res[i] != '\0') {
        if (res[i] != ' ' && space == 0) {
            newres[j] = res[i];
            j++;
            i++;
            space++;
        }
        if (res[i] != ' ' && space > 0) {
            newres[j] = res[i];
            j++;
        }
        i++;
    }
    newres[i] = '\0';
    return newres;
}