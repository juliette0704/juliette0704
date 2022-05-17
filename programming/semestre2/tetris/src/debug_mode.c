/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

void debug_mode()
{
    iserror_t *error = malloc(sizeof(iserror_t));
    stacktogo_t *st = malloc(sizeof(stacktogo_t));
    nb_t *nb = malloc(sizeof(nb_t));
    nb->color = 0;
    DIR *t;
    nb->nboftetrim = 0;
    nb->kdrop = 120;
    nb->kleft = 260;
    nb->kright = 261;
    t = opendir("./tetriminos");
    struct dirent *dir;
    if (t) {
        while ((dir = readdir(t)) != NULL) {
            if (dir->d_name[0] != '.')
                loop_on_file(nb, dir, error, st);
        }
    closedir(t);
    }
    print_debug(nb, st);
}

void loop_on_file(nb_t *nb, struct dirent *dir, iserror_t *error, stacktogo_t *st)
{
    nb->nboftetrim++;
    nb->no = 0;
    nb->sizex = 0;
    nb->sizey = 0;
    error->no = 0;
    char *t = dir->d_name;
    struct stat buf;
    char test[200] = "./tetriminos/";
    char *fin = my_strcat(test, t);
    char max[5000];
    stat(fin, &buf);
    int size = buf.st_size;
    int fd = open(fin, O_RDONLY);
    int n = read(fd, max,size);
    max[n] = '\0';
    check_file_error(max, dir, t, st, nb, error);
}

char **change_tetris(char **tetris)
{
    int j = 0;
    int i = 0;
    while (tetris[i] != NULL) {
        while (tetris[i][j] != '\0') {
            if (tetris[i][j] == ' ' && tetris[i][j + 1] == '\0') {
                tetris[i][j] = '\0';
                j = 0;
            }
            j++;
        }
        i++;
    }
}

void check_file_error(char *file, struct dirent *t, char *name, stacktogo_t *st, nb_t *nb, iserror_t *error)
{
    char **file_tab = str_to_word_array(file);
    // file_tab = change_tetris(file_tab);
    nb->tetrim = my_strcopy(file);
    create_mini_tab(nb);
    int yes = 0;
    int j = 0;
    int i = 0;
    int k = 0;
    char *ju = malloc(50 * sizeof(char));
    while (file_tab[j + 1] != NULL) {
        if (file_tab[j][i] == '\0') {
            j++;
            i = 0;
        }
        if (j == 0) {
            if (!(file_tab[j][i] >= 48 && file_tab[j][i] <= 57)) {
                if (file_tab[j][i] != ' ') {
                    error->no = 1;
                    yes = 1;
                    break;
                }
            } else {
                if (file_tab[j][i] != ' ') {
                    if (i == 0) nb->sizex = file_tab[j][i];
                    else if (i == 2) nb->sizey = file_tab[j][i];
                    else nb->color = file_tab[j][i];
                }
            }
        } else if (file_tab[j][i] != ' ' && file_tab[j][i] != '*') {
            nb->no = 1;
            yes = 1;
            break;
        }
        i++;
    }
    i = 0;
    yes = clement(file_tab, j, i, nb, yes);
    if (file_tab[j][i] != ' ' && file_tab[j][i] != '*') {
            error->no = 1;
            yes = 1;
    }
    for (int o = 0; name[k] != '.'; o++, k++)
        ju[o] = name[k];
    nb->tetris = ju;
    add_element_to_stack(st, nb);
}

void print_debug(nb_t *nb, stacktogo_t *st)
{
    printf("%s\n%s\n", "Key left: KEY_LEFT (260)", "Key right: KEY_RIGHT (261)");
    printf("%s\nKey drop: KEY_DOWN (%d)\n", "Key turn: KEY_UP (259)", 258);
    printf("%s\n%s\n", "Key quit: q (113)", "Key pause:   (32)");
    printf("%s\n%s\n", "Next: Yes", "Level: 1");
    printf("%s\n\n", "Size: 20*10");
    printf("Number of tetriminos: %d\n", nb->nboftetrim);
    int k = 6;
    stacktogo_t *stackend = malloc(sizeof(stacktogo_t));
    stackend = alpha_order(st, k);
    if (st->first->sizex != 0) {
            printf("Tetriminos '%s': ", st->first->x);
            printf("size %c*%c, color %c%s", st->first->sizex, st->first->sizey, st->first->color, st->first->tetrim);
    } else printf("error\n");
}