/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** task
*/

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_getnbr(char const *str)
{
	int i = 0;
	int sign = 1;
	int n = 0;
	
	if (my_strlen(str) > 0) {
		while (str[i] != '\0' && str[i] == '-') {
			i++;
			sign = -1;
			}
		} else
			return 84;
		while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
			n = (n * 10) + (str[i] - '0');
			i++;
		}
		return (sign * n);
}
