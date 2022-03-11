/*
** EPITECH PROJECT, 2021
** the_last.c
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

int quelletypeperm(struct dirent *readfile, int permission)
{
    char *alpha = malloc(sizeof(*alpha));
    if (readfile->d_name[0] == '.')
        return 1;
    perm_owner(permission);
    perm_groupe(permission);
    perm_user(permission);
    printf("  ");
    is_hard_link(readfile);
    name(readfile);
    size(readfile);
    timing(readfile);
    printf("%s  ", readfile->d_name);
    printf("\n");
}

void permission(struct dirent *readfile)
{
    char *file = readfile->d_name;
    int permission = 0;
    struct stat perm;
    permission = stat(file, &perm);
    permission = perm.st_mode;
    quelletypeperm(readfile, permission);
}

void for_l(char *l)
{
    struct dirent *readfile;
    DIR *repo;
    repo = opendir("./");
    readfile = readdir(repo);
    while (readfile) {
        permission(readfile);
        readfile = readdir(repo);
    }
}

void for_a(char *a)
{
    struct dirent *readfile;
    DIR *repo;
    repo = opendir("./");
    readfile = readdir(repo);
    while (readfile) {
        printf("%s  ", readfile->d_name);
        readfile = readdir(repo);
    }
    printf("\n");
}

void pointeur(char *av)
{
    int o = 0;
    int i = 0;
    char *t = "atfrl";
    void (*tab[3])(char*);
    for (; av[i] != '-'; i++);
    i++;
    for (; av[i] != t[o]; o++);
    tab[0] = for_a;
    tab[1] = open_read_for_t;
    tab[2] = open_read;
    tab[3] = open_read_for_t;
    tab[4] = for_l;
    (*tab[o])(av);
}