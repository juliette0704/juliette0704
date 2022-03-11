/*
** EPITECH PROJECT, 2022
** impair
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

void impair_ext(char *str, char *temp, int nb, char *res)
{
    int i = 0;
    int j = 0;
    for (; str[i + 1] != '\0'; j++) {
        if (str[i] != '\0') {
            temp[0] = str[i];
            temp[1] = str[i + 1];
            temp[2] = '\0';
            nb = my_getnbr(temp);
            res[j] = nb;
            i += 2; }
    }
    temp[0] = '0';
    temp[1] = str[i];
    temp[2] = '\0';
    nb = my_getnbr(temp);
    res[j] = nb;
    i++;
    for (int z = 0; res[z] != '\0'; z++)
        my_putchar(res[z]);
    return;
}

void impair(char *str)
{
    int nb = 0;
    char temp[2];
    int j = 0;
    char res[my_strlen(str) / 2 + 1];
    res[my_strlen(str) / 2 + 1] = '\0';
    impair_ext(str, temp, nb, res);
    return;
}