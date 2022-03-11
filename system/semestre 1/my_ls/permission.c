/*
** EPITECH PROJECT, 2021
** permission.c
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

void perm_user(int permission)
{
    if ((permission & S_IROTH) && (permission & __S_IREAD))
        printf("r");
    else
        printf("-");
    if ((permission & S_IWOTH) && (permission & __S_IWRITE))
        printf("w");
    else
        printf("-");
    if ((permission & S_IXOTH) && (permission & __S_IEXEC))
        printf("x");
    else
        printf("-");
}

void perm_groupe(int permission)
{
    if ((permission & S_IRGRP) && (permission & __S_IREAD))
        printf("r");
    else
        printf("-");
    if ((permission & S_IWGRP) && (permission & __S_IWRITE))
        printf("w");
    else
        printf("-");
    if ((permission & S_IXGRP) && (permission & __S_IEXEC))
        printf("x");
    else
        printf("-");
}

void perm_owner(int permission)
{
    if ((permission & S_IRUSR) && (permission & __S_IREAD))
        printf("r");
    else
        printf("-");
    if ((permission & S_IWUSR) && (permission & __S_IWRITE)) 
        printf("w");
    else
        printf("-");
    if ((permission & S_IXUSR) && (permission & __S_IEXEC))
        printf("x");
    else
        printf("-");
}