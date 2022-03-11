/*
** EPITECH PROJECT, 2021
** my_str_isprintable.c
** File description:
** task
*/

int my_str_isprintable(char const *str)
{
    int i = 0;
    while(str[i] != '\0') {
        if(! (str[i] == 127 || (str[i] >= 0 && str[i] < 32)))
            i++;
        return 0;
    }
    return 1;
}
