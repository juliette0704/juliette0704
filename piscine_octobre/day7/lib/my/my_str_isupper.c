/*
** EPITECH PROJECT, 2021
** my_str_isupper.c
** File description:
** task
*/

int my_str_isupper(char const *str)
{
    int i = 0;
    while(str[i] != '\0') {
        if(!(str[i] > 64 && str[i] < 91)) {
            return 0;
        } else {
            i++;
        }
    }
    return 1;
}
