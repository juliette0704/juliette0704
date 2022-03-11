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

ptrfilename* alpha_order(ptrfilename* fbp, int *numberoffiles)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char a = 'A';
    char b = 'A';

    filename *tmp1 = malloc(sizeof(*tmp1));
    tmp1 = fbp->li_adresse;   
    filename *tmp2 = malloc(sizeof(*tmp2));
    tmp2 = tmp1;
    filename *tmp3 = malloc(sizeof(*tmp3));
    tmp3 = tmp2->prev;
    ptrfilename *tmp = malloc(sizeof(*tmp));
    tmp->li_adresse = NULL;
    ptrfilename *first = malloc(sizeof(*first));
    first->li_adresse = fbp->li_adresse;

    for (i = 0; i < *numberoffiles - 1; i++) {
        while (tmp3 != NULL) {
            j += 1;
            a = * (tmp2->filename); // on recup la 1er lettre du 1er nom de fichier
            b = * (tmp3->filename); // on recup la 2eme lettre du nom de fichier
            while (a == b) {// tant qu'on a une égalité, on passe à la lettre suivante pour la comparaison.

                a = * (tmp2->filename+k);
                b=* (tmp3->filename+k);
                k++;
            }
            if (a < b) {// ordre alph : <= ou >= pour le reverse
                if (j == 1) {// code pour gérer l'exception pour le premier élément de la pile.
                    tmp1 = tmp1;
                    tmp2 = tmp1->prev;
                    tmp3 = tmp2->prev;
                }
                else {// si pas le 1er élément de la pile
                    tmp1 = tmp2;
                    tmp2 = tmp2->prev;
                    tmp3 = tmp3->prev;
                }  
            }
            else {
                if (j == 1) { // si on se trouve en début de pile alors :
                //on a une nouvelle tête de pile :
                    first->li_adresse = tmp3;
                //on echange les adresses chainées :
                    tmp->li_adresse = tmp3->prev;
                    tmp3->prev = tmp2;
                    tmp2->prev = tmp->li_adresse;
                //puis on avance...
                    tmp1 = tmp3;
                    tmp2 = tmp1->prev;
                    tmp3 = tmp2->prev;       
                }
                else {
                //on echange les adresses chainées
                    tmp->li_adresse = tmp3->prev;
                    tmp1->prev = tmp3;
                    tmp3->prev = tmp2;
                    tmp2->prev = tmp->li_adresse;
                    //puis on avance...
                    tmp1 = tmp3;
                    tmp2 = tmp2;
                    tmp3 = tmp2->prev;    
                }          
            }
            if (tmp3 == NULL) j = 0;
            k = 0;
            
        }
        //on retourne au début de la pile et on recommence
        tmp1 = first->li_adresse;
        tmp2 = tmp1;
        tmp3 = tmp2->prev;
    }
   return (first); 
}

void open_read_for_t(char *av)
{
    struct dirent *readfile;
    struct ptrfilename *fbp = malloc(sizeof(*fbp));
    fbp->li_adresse = NULL;
    DIR *repo;
    int *numberoffiles = malloc(sizeof(int));
    *numberoffiles = 0;
    repo = opendir("./");
    readfile = readdir(repo);
    while (readfile) {
        numberoffiles += 1;
        quelletype(readfile, fbp);
        readfile = readdir(repo);
    }
    fbp = alpha_order(fbp, numberoffiles);
    printf_list(fbp);
    printf("\n");
}
