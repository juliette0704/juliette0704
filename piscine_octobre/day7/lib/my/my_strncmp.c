/*
** EPITECH PROJECT, 2021
** my_strncmp.c
** File description:
** task
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i= 0;
    int j = 0;
    int size1 = 0;
    int size2 = 0;
    
    while(i < n && s1[i] != '\0') {
        i++;
    }
    while(j < n && s2[j] != '\0') {
        j++;
    }
    if(j == i)
        return 0;
    if(i > j)
        return 1;
    if(i < j)
        return -1;
}
