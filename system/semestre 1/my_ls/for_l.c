/*
** EPITECH PROJECT, 2021
** for_l.c
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
/*
struct test* total_blocks(struct dirent *readfile)
{
    int i = 0;
    test *totblock = malloc(sizeof(*totblock));
    readfile->d_reclen = totblock->blocks[i];
    i++;
    return totblock;
}
*/
void is_hard_link(struct dirent *readfile)
{
    char *file = readfile->d_name;
    int hard = 0;
    struct stat hardlink;
    hard = stat(file, &hardlink);
    printf("%d  ", hardlink.st_nlink);
}

void timing(struct dirent *readfile)
{
    char *result = malloc(sizeof(*result));
    char *file = readfile->d_name;
    time_t timer = time(NULL);
    struct stat mod_time;
    stat(file, &mod_time);
    char size[600];
    result = ctime(&timer);
    for (int i = 4; i < 16; i++)
         printf("%c", result[i]);
    printf("  ");
    //total_blocks(readfile);
}

void size(struct dirent *readfile)
{
    char *file = readfile->d_name;
    struct stat buf;
    stat(file, &buf);
    int size = buf.st_size;
    printf("%d  ", size);
}

void name(struct dirent *readfile)
{
    char *file = readfile->d_name;
    int name = 0;
    struct stat dispname;
    name = stat(file, &dispname);
    struct passwd *name_user = getpwuid(dispname.st_uid);
    printf("%s  ", name_user->pw_name);
    struct group *name_group = getgrgid(dispname.st_uid);
    printf("%s  ", name_group->gr_name);
}