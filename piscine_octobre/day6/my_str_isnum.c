/*
** EPITECH PROJECT, 2021
** my_str_isnum.c
** File description:
** task
*/

int my_str_isnum(char const *str)
{
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] > 47 && str[i] < 58)
            i++;
        return 0;
    }
    return 1;
}
