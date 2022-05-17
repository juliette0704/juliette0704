/*
** EPITECH PROJECT, 2022
** solver.h
** File description:
** solver
*/

typedef struct nb
{
    int x;
    int y;
} nb_t;

typedef struct elmtogo
{
    int x;
    int y;
    struct elmtogo *next;
} elmtogo_t;

typedef struct maze
{
    char **maze;
    int x;
    int y;
} maze_t;

typedef struct stacktogo
{
    struct elmtogo *first;
} stacktogo_t;

char **str_to_word_array(char *chaine);
nb_t *unstack(struct stacktogo *stackToDepile);
int unstacke(struct stacktogo *stackToDepile);
struct stacktogo *reverse_stack(struct stacktogo *stacktoreverse);
void add_element_to_stack(stacktogo_t *thestack, nb_t *newx, nb_t *newy);
int verif_front(maze_t *mazet, nb_t *nb, stacktogo_t *sol);
int verif_back(maze_t *mazet, nb_t *nb, stacktogo_t *sol);
int verif_up(maze_t *mazet, nb_t *nb, stacktogo_t *sol);
