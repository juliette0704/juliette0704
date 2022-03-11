/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** task
*/

int my_str_islower(char const *str)
{
    int i = 0;
    while(str[i] != '\0') {
        if(!(str[i] > 96 && str[i] < 123)) {
            return 0;
        } else {
            i++;
        }
    }
    return 1;
}
