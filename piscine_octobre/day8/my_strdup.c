/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** task
*/

#include <stdlib.h>

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int size = 0;
    
    while(src[size] != '\0')
    {
        size++;
    } 
    str = malloc(sizeof(char) * size);
    while(i < size)
    {
        str[i] = src[i];
        i = i + 1;
    }
    return (&str[0]);
}

int main(void)
{
//    char src[] = "coucouuuuuu";
    my_strdup(src);
    printf("%s", my_strdup());
       
}
