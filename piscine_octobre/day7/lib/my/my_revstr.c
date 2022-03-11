/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** task
*/

int my_strlen2(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    int i;  
    int len;
    char carac;
    
    len  = my_strlen2(str) -1;
    while (i < len){
        carac = str[len];
        str[len] = str[i];
        str[i] = carac;
        len--;
        i++;
    }
    return (str);
}
