/*
** EPITECH PROJECT, 2021
** str_to_word_array.c
** File description:
** str
*/

#include "my.h"

int calc_space(int word_size, char *chaine, int new_count)
{
    while (chaine[new_count] != ' ' && chaine[new_count] != '\0') {
        word_size++;
        new_count++;
    }
    return word_size;
}

int my_cond(char *chaine, int count)
{
    if (chaine[count] == ' ')
        count++;
    return count;
}

char **str_to_word_array(char *chaine)
{
    int size_chaine = 0, row = 0;
    int total_nb_char = 0, count = 0;
    total_nb_char = my_strlen(chaine);
    char **arr = (char**)malloc(total_nb_char * sizeof(char*));
    while (chaine[count] != '\0') {
        int col = 0;
        int new_count = count;
        int word_size = 0;
        word_size = calc_space(word_size, chaine, new_count);
        arr[row] = (char*)malloc((word_size + 1) * sizeof(char));
        for (int z = 0; z < word_size; z++) {
            arr[row][col] = chaine[count]; 
            col++;
            count++;
        }
        arr[row][col] = '\0';
        row++;
        count = my_cond(chaine, count);
    }
    return arr;
}
