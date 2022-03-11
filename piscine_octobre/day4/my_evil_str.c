/*
** EPITECH PROJECT, 2021
** my_evil_str.c
** File description:
** task
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int i;
    int len;
    char carac;

    i = 0;
    len = my_strlen(str) - 1;
    while (i < len){
        carac = str[len];
        str[len] = str[i];
        str[i] = carac;
        len--;
        i++;
    }
    return (str);
}
