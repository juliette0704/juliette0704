/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** task
*/

char *my_strncpy(char *dest,char const *src,int n)
{
    int i = 0;
    while(src[i] != '\0' && i < n -1) {
		dest[i] = src[i];
		i++;
    }
    return (src);
}
