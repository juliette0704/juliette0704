/*
** EPITECH PROJECT, 2021
** reader.c
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

void detection(char av, bool *whatflag)
{
    if (av == 'l') whatflag->flag_l = 1;
    if (av == 'a') whatflag->flag_a = 2;
    if (av == 't') whatflag->flag_t = 3;
}

void for_atous(char *a)
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

void find2(bool * whatflag, int at, int lt)
{
    if (at == 5 && whatflag->flag_l == 0) for_a("rien");
        else if (lt == 4 && whatflag->flag_a == 0) for_l("rien");
}

void find(bool *whatflag)
{
    int at = whatflag->flag_a + whatflag->flag_t;
    int la = whatflag->flag_l + whatflag->flag_a;
    int lt = whatflag->flag_l + whatflag->flag_t;
    if (at == 3 && la == 0) open_read("rien");
    if (at == 2 && la == 2) for_a("rien");
    if (la == 3) for_ltous("rien");
        else if (whatflag->flag_t == 1 && la == 3) for_ltous("rien");
            else if (whatflag->flag_l == 1 && at == 0) for_l("rien");
    else find2(whatflag, at, lt);
 }

void lecture(char **av)
{
    bool *whatflag = malloc(sizeof(*whatflag));
    for(int i = 0; av[i] != NULL; i++) {
        for(int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][j] == '-') {
                j++;
                detection(av[i][j], whatflag);
            }
        }
    }
    find(whatflag);
}