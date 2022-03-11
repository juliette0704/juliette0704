/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** task
*/

int my_strlen4(char const *s1)
{
    int i = 0;
    while (s1[i] != '\0') {
        i++;
    }
    return (i);
}
int my_strcmp(char const *s1, char const *s2)
{
    my_strlen4(s1);
    my_strlen4(s2);
    int j = 0;
    if (my_strlen4(s1) > my_strlen4(s2)) {
        while( s1[j] != '\0') {
            if(s1[j] == s2[j]) {
                j++;
            } else if(s1[j] != s2[j]) {
                return (0);
            }
        }
    }
    if (my_strlen4(s2) > my_strlen4(s1)) {
        while(s2[j] != '\0') {
            if(s2[j] == s1[j])
                j++;
            else
                return (0);
        }
    }
    if(my_strlen4(s2) == my_strlen4(s1)) {
        while(s2[j] != '\0') {
                if(s2[j] == s1[j])
                    j++;
                else
                    return (0);
                
            }
    }
    return (1);
}
