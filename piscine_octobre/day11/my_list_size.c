/*
** EPITECH PROJECT, 2021
** my_list_size.c
** File description:
** task
*/

#include "list.h"
#include <unistd.h>

int my_list_size(linked_list_t const *begin){
    struct linked_list *dest = begin;
    int i = 0;
    while(dest != NULL) {
        i++;
        dest = dest->next;
    }
    return (i);
}
