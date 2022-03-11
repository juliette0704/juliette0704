/*
** EPITECH PROJECT, 2021
** my_list_size.c
** File description:
** task
*/

#include "list.h"
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


int my_list_size(linked_list_t const *begin){
    struct linked_list *dest = begin;
    int i = 0;
    while(dest != NULL) {
        i++;
        dest = dest->next;
    }
    return (i);
}

int main(int ac, char **av)
{
    linked_list_t *test = my_params_to_list(ac, av);
    int i = my_list_size(test);
    
    printf("%d",i);
}
