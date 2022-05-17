/*
** EPITECH PROJECT, 2021
** str_to_word_array
** File description:
** my_lib
*/

#include "my.h"
#include <stdlib.h>

int cont_space(char *str, char delim)
{
    int cont = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim)
            cont++;
    }
    return cont;
}

char **verification(char **tab, char *str, char delim)
{
    int y = 0;
    int cont;
    for (int i = 0; i < my_strlen(str);) {
        for (cont = i; str[cont] != '\0'; cont++) {
            if (str[cont] == delim)
                break;
        }
        cont -= i;
        tab[y] = malloc(sizeof(char) * (cont + 1));
        tab[y][cont] = '\0';
        y++;
        i += cont + 1;
    }
    return tab;
}

char **my_str_to_word_array(char *str, char delim)
{
    int len = cont_space(str, delim) + 1;
    char **tab = malloc(sizeof(char *) * (len + 1));
    tab = verification(tab, str, delim);
    tab[len] = NULL;
    int x = 0;
    int y = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == delim) {
            i++;
            y++;
            x = 0;
        }
        tab[y][x] = str[i];
        if (str[i] != delim)
            x++;
    }
    return tab;
}
