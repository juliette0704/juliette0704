/*
** EPITECH PROJECT, 2021
** char_to_int.c
** File description:
** task01
*/

int char_to_int(char *str)
{
    int res = 0, i = 0;
    if (str[i] == '-')
        i++;
    for ( ; str[i] != '\0' ; i++) {
        res *= 10;
        res += str[i] - '0';
    }
    if (str[0] == '-')
        res *= -1;
    return res;
}
