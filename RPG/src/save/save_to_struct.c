/*
** EPITECH PROJECT, 2022
** save_to_struct.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

char **remove_space_ext(char **tab, int i, int j)
{
    if (tab[i][j] == ' ') {
        for (; tab[i][j] == ' '; j--);
        tab[i][j + 1] = '\n';
        tab[i][j + 2] = '\0';
    }
    return tab;
}

char **remove_space(char **tab)
{
    int j = 0;
    for (int i = 0; tab[i] != NULL; i++) {
        j = my_strlen(tab[i]) - 2;
        tab = remove_space_ext(tab, i, j);
    }
    return tab;
}

char **remove_remark_ext(char **tab, int i)
{
    for (int j = 1; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == '#') {
            tab[i][j] = '\n';
            tab[i][j + 1] = '\0';
        }
    }
    return tab;
}

char **remove_remark(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i][0] != '#') {
            tab = remove_remark_ext(tab , i);
        }
    }
    return tab;
}

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

char *read_map(void)
{
    int file_size = 1000;
    int fd = open("save/save", O_RDONLY);
    int size;
    if (open("save/save", O_RDONLY) == - 1) {
        write(2, "MAP INVALID\n", 12);
        exit(84);
    }
    if (file_size <= 0) {
        write(2, "MAP INVALID\n", 12);
        exit(84);
    }
    char *map = malloc(file_size + 1);
    size = read(fd, map, file_size);
    map[size] = '\0';
    close(fd);
    return map;
}

void file_to_struct(global_t *m)
{
    char *file = read_map();
    char **tab = my_str_to_word_array(file, '\n');
    free(file);
    tab = remove_remark(tab);
    tab = remove_space(tab);
    m->life[0].life = my_getnbr(tab[0]);
    m->scene = my_getnbr(tab[1]);
    m->life_slime = my_getnbr(tab[2]);
    for (int i = 0; i < m->nb_slime; i++)
        m->enemy[i].life = my_getnbr(tab[2]);
    m->hit_boss[0].life_boss = my_getnbr(tab[3]);
    m->hit_boss[1].life_boss = my_getnbr(tab[3]);
}
