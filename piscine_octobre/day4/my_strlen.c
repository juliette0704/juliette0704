/*
** EPITECH PROJECT, 2021
** my_strlem.c
** File description:
** task
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
