/*
** EPITECH PROJECT, 2021
** my_str_isalpha.c
** File description:
** task
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    while(str[i] != '\0') {
        if(!((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))) {
            return 0;
        } else {
            i++;
        }
    }
    return 1;
}
