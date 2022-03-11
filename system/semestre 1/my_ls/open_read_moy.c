/*
** EPITECH PROJECT, 2021
** open_read_moy.c
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

int quelletype(struct dirent *readfile, struct ptrfilename *ptr)
{
    char *alpha = malloc(sizeof(*alpha));
    struct filename *newfilename = malloc(sizeof(*newfilename));
    if (readfile->d_name[0] == '.')
        return 1;
    newfilename->filename = &readfile->d_name;
    if (ptr->li_adresse == NULL) newfilename->prev = NULL;
        else newfilename->prev = ptr->li_adresse;
    ptr->li_adresse = newfilename;
}

void printf_list(ptrfilename *ptr)
{
    filename *ptrname = malloc(sizeof(*ptrname));
    ptrname->filename = ptr->li_adresse->filename;
    ptrname->prev = ptr->li_adresse->prev;
    while (ptrname->prev != NULL) {
        printf("%s | ", ptrname->filename);
        ptrname = ptrname->prev;
    }
}

