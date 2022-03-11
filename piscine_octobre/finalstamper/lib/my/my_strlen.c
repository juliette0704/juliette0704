/*
** EPITECH PROJECT, 2021
** MY STRLEN
** File description:
** Returns length of str
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
