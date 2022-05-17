/*
** EPITECH PROJECT, 2021
** edit_stack.c
** File description:
** dante
*/

#include "my.h"
#include "generator.h"

nb_t *unstack(struct stacktogo *stackToDepile)
{
    nb_t *nb = malloc(sizeof(nb_t));
    elmtogo_t *elementDepile = stackToDepile->first;

    if (stackToDepile != NULL && stackToDepile->first != NULL) {
        nb->x = elementDepile->x;
        nb->y = elementDepile->y;
        stackToDepile->first = elementDepile->next;
        free(elementDepile);
        return nb;
    }
    return 0;
}

int unstacke(struct stacktogo *stackToDepile)
{
    int unstacknumber = 0;
    elmtogo_t *elementDepile = stackToDepile->first;

    if (stackToDepile != NULL && stackToDepile->first != NULL) {
        unstacknumber = elementDepile->x;
        stackToDepile->first = elementDepile->next;
        free(elementDepile);
        return unstacknumber;
    }
    return 0;
}

struct stacktogo *reverse_stack(struct stacktogo *s)
{
    nb_t *nb = malloc(sizeof(nb_t));
    struct stacktogo *tmp = malloc(sizeof(*tmp));
    struct elmtogo *elementmp = malloc(sizeof(*elementmp));
    tmp->first = NULL;
    elementmp = s->first;
    while (s->first != NULL)
        add_element_to_stack(tmp, unstack(s), unstack(s));
    return tmp;
}

void add_element_to_stack(stacktogo_t *thestack, nb_t *newx, nb_t *newy)
{
    struct elmtogo *new = malloc(sizeof(elmtogo_t));
    new->x = newx->x;
    new->y = newy->y;
    new->next = thestack->first;
    thestack->first = new;
}
