/*
** EPITECH PROJECT, 2021
** generator.h
** File description:
** gene
*/

typedef struct nb
{
    int x;
    int y;
} nb_t;

typedef struct test
{
    char **test;
    int x;
    int y;
} test_t;

typedef struct maze
{
    char **maze;
    int x;
    int y;
} maze_t;

typedef struct elmtogo
{
    int x;
    int y;
    struct elmtogo *next;
} elmtogo_t;

typedef struct stacktogo
{
    struct elmtogo *first;
} stacktogo_t;

typedef struct visited
{
    int x;
    int y;
    struct visited *next;
} visited_t;

typedef struct stackv
{
    struct visited *next;
} stackv_t;

struct nb *unstack(struct stacktogo *stackToDepile);
struct stacktogo *reverse_stack(struct stacktogo *stacktoreverse);
void add_element_to_stack(stacktogo_t *thestack, struct nb *newx, struct nb *newy);
void init_maze(int x, int y);
int check_errors(int x, int y);