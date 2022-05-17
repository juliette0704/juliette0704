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

typedef struct stackv
{
    struct visited *next;
} stackv_t;

struct nb *unstack(struct stacktogo *);
struct stacktogo *reverse_stack(struct stacktogo *);
void add_element_to_stack(stacktogo_t *, struct nb *, struct nb *);
void init_maze(int x, int y, int ac);
int check_errors(int x, int y);
int my_strcmp(char const *s1, char const *s2);
void for_down(nb_t *nb, maze_t *maze, stacktogo_t *);
void for_up(nb_t *nb, maze_t *maze, stacktogo_t *);
void for_right(nb_t *nb, maze_t *maze, stacktogo_t *);
void for_left(nb_t *nb, maze_t *maze, stacktogo_t *);
maze_t *print_square(maze_t *maze);
maze_t *create_square(maze_t *maze);
void imperfect_maze(maze_t *maze);
void loop_maze(nb_t *nb, stacktogo_t *s, maze_t *m);
int is_a_neigbourg(maze_t *maze, nb_t *nb);
int verif_if_unstack(stacktogo_t *, nb_t *, maze_t *, int);
int is_it_visited(maze_t *maze, nb_t *, stacktogo_t *st);
void loop_maze(nb_t *nb, stacktogo_t *s, maze_t *m);
void switch_random(nb_t *nb, maze_t *, stacktogo_t *, int);
void loop_maze1(nb_t *nb, stacktogo_t *s, maze_t *m);
int verif_if_unstack1(stacktogo_t *stackv, nb_t *nb, maze_t *maze, int end);
int is_a_neigbourg1(maze_t *maze, nb_t *nb);
void switch_random1(nb_t *nb, maze_t *maze, stacktogo_t *stackv, int random);
void for_down1(nb_t *nb, maze_t *maze, stacktogo_t *stackv);
void for_up1(nb_t *nb, maze_t *maze, stacktogo_t *stackv);
void for_right1(nb_t *nb, maze_t *maze, stacktogo_t *stackv);
void for_left1(nb_t *nb, maze_t *maze, stacktogo_t *stackv);
