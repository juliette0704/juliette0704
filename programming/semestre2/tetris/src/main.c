/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

void for_clem_clem(char *name, char **res, int i)
{
    res[i] = malloc(sizeof(char) * my_strlen(name));
    res[i] = my_strcopy(name);
}

void for_clem(all_t *glo)
{
    DIR *t;
    char **res = malloc(sizeof(char *) * 30);
    t = opendir("./tetriminos");
    struct dirent *dir;
    int i = 0;
    if (t) {
        while ((dir = readdir(t)) != NULL) {
            if (dir->d_name[0] != '.') {
                for_clem_clem(dir->d_name, res, i);
                i++;
            }
        }
    closedir(t);
        glo->file_na = res;;
    }
}

int main(int ac, char **av)
{
    WINDOW *win;
    int j = 0;
    int mode = 0;
    int help = 0;
    int opt = 0;
    for (int i = 0; av[i] != NULL; i++) {
        if (av[i][j] == '\0') {
            i++;
            j = 0;
        }
        if (my_strcmp(av[i], "--help") == 1) help = 1;
        if (my_strcmp(av[i], "-D") == 1) mode = 1;
    }
    if (ac == 1) launch_game(ac, av);
    else if (mode == 1) debug_mode();
    else if (help == 1) help_mode();
    else
        return 84;
}
