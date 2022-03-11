/*
** EPITECH PROJECT, 2021
** for_all.c
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

int quelletypepermtous(struct dirent *readfile, int permission)
{
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

void permissiontous(struct dirent *readfile)
{
    char *file = readfile->d_name;
    int permission = 0;
    struct stat perm;
    permission = stat(file, &perm);
    permission = perm.st_mode;
    quelletypepermtous(readfile, permission);
}

void for_ltous()
{
    struct dirent *readfile;
    DIR *repo;
    repo = opendir("./");
    readfile = readdir(repo);
    while (readfile) {
        permissiontous(readfile);
        readfile = readdir(repo);
    }
}