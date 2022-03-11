/*
** EPITECH PROJECT, 2021
** tot.h
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

typedef struct bool bool;
struct bool
{
    int flag_l;
    int flag_a;
    int flag_t;
};

typedef struct alpha alpha;
struct alpha
{
    char **temp;
    char *file;
};

typedef struct filename filename;
struct filename
{
    char *filename;
    filename *prev;
};

typedef struct ptrfilename ptrfilename;
struct ptrfilename
{
    filename *li_adresse;
};

typedef struct test test;
struct test
{
    unsigned short *blocks;
};

void perm_groupe(int permission);
void perm_owner(int permission);
void perm_user(int permission);
void timing(struct dirent *readfile);
void is_hard_link(struct dirent *readfile);
void size(struct dirent *readfile);
void name(struct dirent *readfile);
int quelletypepermtous(struct dirent *readfile, int permission);
void permissiontous(struct dirent *readfile);
void for_ltous();
filename *changeadd(filename *tmp1, filename *tmp2, filename *tmp3, int j, ptrfilename *first, ptrfilename *tmp);
filename *reverse(filename *tmp1, filename *tmp2, filename *tmp3, int j);
filename* recuperation(int j, char a , char b, filename *tmp2, filename *tmp3, filename *tmp1, ptrfilename *first, ptrfilename *tmp);
ptrfilename *alpha_order(ptrfilename *fbp, int *numberoffiles);
void printf_list(ptrfilename *ptr);
void open_read_for_t(char *av);
int quelletype(struct dirent *readfile, struct ptrfilename *ptr);
void detection(char av, bool *whatflag);
void for_atous(char *a);
void find2(bool * whatflag, int at, int lt);
void find(bool *whatflag);
void lecture(char **av);
int quelletypeperm(struct dirent *readfile, int permission);
void permission(struct dirent *readfile);
void for_l(char *l);
void for_a(char *a);
void pointeur(char *av);
int quelletypeforchemin(struct dirent *readfile);
void chemin(char *travel);
void other(char **av);
void open_read(char *av);
struct test* total_blocks(struct dirent *readfile);