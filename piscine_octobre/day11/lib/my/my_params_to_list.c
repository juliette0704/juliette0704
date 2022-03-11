/*
** EPITECH PROJECT, 2021
** my_params_to_list.c
** File description:
** task
*/

#include "list.h"
#include <stddef.h>
#include <unistd.h>

linked_list_t *def(char *s1, struct linked_list * next)
{
    struct linked_list *tmp;
    tmp = malloc(sizeof(linked_list_t*));
    tmp->data =	s1;
    tmp->next =	next;
    return (tmp);
}

linked_list_t *my_params_to_list(int ac, char *const *av)
{
    struct linked_list_t *s5;
    s5 = NULL;
    for (int i = 0; i < ac; i++) {
        s5 = def(av[i], s5);
    }
    return (s5);
}
