/*
** EPITECH PROJECT, 2022
** save_to_struct.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int char_to_int(char *str)
{
    int i = 1, res = 0, multiply = 1;
    int neg = 0;
    if (str[0] == '-') {
        i++;
        neg++; }
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return 0; }
    i--;
    if (neg == 1) {
        while (i >= 1) {
            res += ((str[i] - 48) * multiply);
            i--;
            multiply *= 10; }
        res *= -1;
    } else {
        while (i >= 0) {
            res += ((str[i] - 48) * multiply);
            i--;
            multiply *= 10; } }
    return res;
}

char *read_file()
{
    int n = 1;
    char *max = malloc(1000 + 1* sizeof(char));
    int fd = 0;
    fd = open("./save/save.txt", O_RDONLY);
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
    m->life[0].life = char_to_int(filetab[1]);
}