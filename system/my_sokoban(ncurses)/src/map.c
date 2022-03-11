/*
** EPITECH PROJECT, 2021
** map.c
** File description:
** map
*/

#include "my.h"
#include "soko.h"
#include <stdbool.h>

bool verif_charac_map(char characmap)
{
    char *validcharac = "#\nXOP ";
    bool characvalid = false;

    for (int j = 0; validcharac[j] != '\0'; j++) {
        if (characmap == validcharac[j])
            characvalid = true;
    }
    return characvalid;
}

bool check_equality(int *tab)
{
    if (tab[player] != 1) return false;
    if (tab[O] != tab[X]) return false;
    return true;
}

bool verification_map(char *map)
{
    char *characmap = "POX#";
    int tab[4] = {0};

    for (int i = 0; map[i] != '\0'; i++) {
        if (verif_charac_map(map[i]) == false)
            return false;
        for (int j = 0; characmap[j]; j++) {
            if (map[i] == characmap[j])
                tab[j]++;
        }
    }
    return check_equality(tab);
}

int read_map(char **av)
{
    struct stat buf;
    stat(av[1], &buf);
    int size = buf.st_size;
    int n = 1;
    char max[size];
    int fd = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        write(2, "ERROR", 5);
        return 1;
    }
    n = read(fd, max, size);
    max[size] = '\0';
    close(fd);
    if (init_game(max) == 84)
        return 1;
    return 0;
}