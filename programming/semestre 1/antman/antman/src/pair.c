/*
** EPITECH PROJECT, 2022
** pair
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

void pair_ext(int nb, char *res, char *str, char *temp)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; j++) {
        if (str[i + 1] != '\0') {
            temp[0] = str[i];
            temp[1] = str[i + 1];
            temp[2] = '\0';
            nb = my_getnbr(temp);
            res[j] = nb;
            i += 2;
        } else {
            temp[0] = '0';
            temp[1] = str[i];
            temp[2] = '\0';
            nb = my_getnbr(temp);
            res[j] = nb;
            i++; }
    }
    for (int h = 0; res[h] != '\0'; h++)
        my_putchar(res[h]);
    return;
}

void pair(char *str)
{
    int nb = 0;
    char temp[2];
    int test = my_strlen(str) / 2;
    char res[test];
    res[my_strlen(str) / 2] = '\0';
    pair_ext(nb, res, str, temp);
    return;
}