/*
** EPITECH PROJECT, 2021
** MY SHOW WORD ARRAY
** File description:
** Displays content of array of words
*/

#include <stdlib.h>

void my_putchar(char c);

void my_putstr(char const *str);

char *my_show_word_array(char * const *tab)
{
    int i;
    for (i = 0; tab[i] != '\0'; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return ("OK");
}
