/*
** EPITECH PROJECT, 2021
** MY GETNBR
** File description:
** Locate nbr in str
*/

#include <unistd.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

int my_atoi(char const *str, int negatives)
{
    int numlen = my_strlen(str);
    int num = 0;
    for (int i = 0; i < numlen; i++) {
        num = num * 10 + (str[i] - 48);
    }
    for (int j = 0; j <= negatives; j++) {
        num = -num;
    }
    return (num);
}

int my_getnbr(char const *str)
{
    int i = 0, negatives = 0, got_a_number = 0, num = 0;
    char *strnbr;
    while (((str[i] > 47) && (str[i] < 58)) || str[i] == 45) {
        if (got_a_number == 0 && str[i] == 45) {
            negatives += 1;
        } else if (str[i] != 45) {
            got_a_number = 1;
            strnbr = my_strcat(strnbr, str[i]);
        }
        i++;
    }
    int finalnum = my_atoi(strnbr, negatives);
    return (finalnum);
}
