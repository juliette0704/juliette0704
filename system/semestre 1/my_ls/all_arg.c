/*
** EPITECH PROJECT, 2021
** alpha.c
** File description:
** task
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include "tot.h"

void all_flags(char *av)
{
}

void pointeur_all_flags(char *av)
{
    int o = 0;
    int i = 0;
    char *t = "atfrl";
    void (*tab[5])(char*);
    for (; av[i] != t[o]; o++);
    tab[0] = for_a;
    tab[1] = open_read_for_t;
    tab[2] = open_read;
    tab[3] = open_read_for_t;
    tab[4] = for_l;
    (*tab[o])(av);
}