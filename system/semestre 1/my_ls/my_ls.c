/*
** EPITECH PROJECT, 2021
** my_ls.c
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

int quelletypeforchemin(struct dirent *readfile)
{
    char *alpha = malloc(sizeof(*alpha));
    if (readfile->d_name[0] == '.')
        return 1;
    printf("%s  ", readfile->d_name);
}

void chemin(char *travel)
{
    struct dirent *readfile;
    DIR *repo;
    repo = opendir(travel);
    readfile = readdir(repo);
    while (readfile) {   
        quelletypeforchemin(readfile);
        readfile = readdir(repo);
    }
    printf("\n");
}

void other(char **av)
{
    if (av[1][0] == '.' || av[1][0] == '/') chemin(av[1]);
    if (av[1][0] == '-') pointeur(av[1]);
}

void open_read(char *av)
{
    struct dirent *readfile;
    DIR *repo;
    repo = opendir("./");
    readfile = readdir(repo);
    while (readfile) {
        quelletypeforchemin(readfile);
        readfile = readdir(repo);
    }
    printf("\n");
}

int main(int ac, char **av)
{
    unsigned short oui = 0;
    //si pas assez ou trop de ac ->> erreur 84
    int x = 1;
    int carac = 0;
    if (ac == 1) open_read(av[1]);
    if (ac == 2) other(av);
    if (ac > 2) {
        while (x < ac) {
            if (av[x][2] == '\0') carac = carac;
                else carac++;
                x++;
        }
        if (carac == 0) lecture(av);
        if (carac > 0) printf("zero");
    }
}