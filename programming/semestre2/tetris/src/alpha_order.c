/*
** EPITECH PROJECT, 2021
** create.c
** File description:
** cretae
*/

#include "my.h"
#include "tetris.h"
#include <time.h>

stacktogo_t *alpha_order(stacktogo_t *fbp, int numberoffiles)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char a = 'A';
    char b = 'A';
    elmtogo_t *tmp1 = malloc(sizeof(elmtogo_t));
    tmp1 = fbp->first;   
    elmtogo_t *tmp2 = malloc(sizeof(elmtogo_t));
    tmp2 = tmp1;
    elmtogo_t *tmp3 = malloc(sizeof(elmtogo_t));
    tmp3 = tmp2->next;
    stacktogo_t *tmp = malloc(sizeof(stacktogo_t));
    tmp->first = NULL;
    stacktogo_t *first = malloc(sizeof(stacktogo_t));
    first->first = fbp->first;

    for (i = 0; i < numberoffiles - 1; i++) {
        while (tmp3 != NULL) {
            j += 1;
            a = *(tmp2->x);
            b = *(tmp3->x);
            while (a == b) {
                a = *(tmp2->x+k);
                b= *(tmp3->x+k);
                k++;
            }
            if (a < b) {
                if (j == 1) {
                    tmp1 = tmp1;
                    tmp2 = tmp1->next;
                    tmp3 = tmp2->next;
                }
                else {
                    tmp1 = tmp2;
                    tmp2 = tmp2->next;
                    tmp3 = tmp3->next;
                }
            }
            else {
                if (j == 1) {
                    first->first = tmp3;
                    tmp->first = tmp3->next;
                    tmp3->next = tmp2;
                    tmp2->next = tmp->first;
                    tmp1 = tmp3;
                    tmp2 = tmp1->next;
                    tmp3 = tmp2->next;
                }
                else {
                    tmp->first = tmp3->next;
                    tmp1->next = tmp3;
                    tmp3->next = tmp2;
                    tmp2->next = tmp->first;
                    tmp1 = tmp3;
                    tmp2 = tmp2;
                    tmp3 = tmp2->next;
                }
            }
            if (tmp3 == NULL) j = 0;
            k = 0;
        }
        tmp1 = first->first;
        tmp2 = tmp1;
        tmp3 = tmp2->next;
    }
    while (first->first->next != NULL) {
            printf("Tetriminos '%s': ", first->first->x);
        if (first->first->sizex != 0 && first->first->no != 1)
            printf("size %c*%c, color %c%s", first->first->sizex, first->first->sizey, first->first->color, first->first->tetrim);
        else printf("error\n");
        unstack(first);
    }
   return (first); 
}
