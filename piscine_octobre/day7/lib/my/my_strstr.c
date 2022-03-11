/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** task
*/

int compare(char *s1, char *s2)
{
    int i = 0;
    while( s1[i] != '\0') {
        if(s1[i] == s2[i]) {
            i++;
        } else {
            return (0);
        }
    }
    return (1);
}

char *my_strstr(char *str, char const *to_find)
{
    while(*str != '\0') {
        if(*str == *to_find) {
            if (compare(to_find, str) == 1) {
                return (str);
            }
        }
        str++;       
    }
    return (0);
}
