/*
** EPITECH PROJECT, 2022
** save_to_struct.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

char *read_file()
{
    int n = 1;
    char *max = malloc(1000 + 1 * sizeof(char));
    int fd = 0;
    fd = open("./save/save", O_RDONLY);
    n = read(fd, max, 1000);
    max[1000] = '\0';
    close(fd);
    return max;
}

void file_to_struct(global_t *m)
{
    char *file = read_file();
    char **filetab = my_str_to_word_array(file, '=');
    // printf(filetab[1]);
    m->life[0].life = my_getnbr(filetab[1]);
}