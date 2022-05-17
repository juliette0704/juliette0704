/*
** EPITECH PROJECT, 2021
** tetris.h
** File description:
** square
*/

typedef struct map
{
    char **map;
    int x;
    int y;
} map_t;

typedef struct pieces
{
    int x;
    int y;
} pieces_t;

typedef struct cell
{
    int x;
    int y;
    int color;
    struct family *parent;
} cell_t;

typedef struct family
{
    cell_t **kids;
} family_t;

typedef struct score
{
    int score;
    int timer;
    int line;
    int level;
} score_t;


typedef struct elmtogo
{
    char *x;
    int sizex;
    int sizey;
    int color;
    int no;
    char *tetrim;
    int nboftetrim;
    struct elmtogo *next;
} elmtogo_t;

typedef struct stacktogo
{
    struct elmtogo *first;
} stacktogo_t;

typedef struct iserror
{
    int no;
} iserror_t;

typedef struct nb
{
    int color;
    int sizex;
    int sizey;
    int no;
    char *tetrim;
    char *tetris;
    int nboftetrim;
    int kleft;
    int kright;
    int kdrop;
} nb_t;

typedef struct all
{
    iserror_t *err;
    char **file;
    nb_t *num;
    cell_t ***grid;
    family_t *next;
    family_t *current;
    int lar;
    int lon;
    clock_t cloc;
    WINDOW *win;
    map_t *map;
    score_t *sco;
    char **file_na;
} all_t;

char **str_to_word_array(char *chaine);
family_t *create_family(char *str);
all_t *create_glo(void);
void move_current(all_t *glo, char c);
void print_grid(all_t *glo);
void gameloop(all_t *glo, map_t *map);
void launch_game(int ac, char **av);
void print_double_array(char **array, int nbcol, int line);
char *choose_random(all_t *glo);
void create_map(map_t *map);
int cant_move_bot(all_t *glo);
void reset_grid(all_t *glo);
void move_left(all_t *glo);
void move_right(all_t *glo);
void pause_game(all_t *glo);
void move_print_sleep(all_t *glo, char c);
void change_current(all_t *glo);
score_t *create_score(void);
void print_next(all_t *glo);
void print_score(all_t *glo);
void for_clem(all_t *glo);
int tab_len(char **tab);
void debug_mode();
char *my_strcopy(char *str);
stacktogo_t* alpha_order(stacktogo_t *fbp, int numberoffiles);
void add_element_to_stack(stacktogo_t *thestack, nb_t *newx);
int my_strcmp(char *s1, char *s2);
int clement(char **file_tab, int j, int i, nb_t *nb, int yes);
void loop_on_file(nb_t *nb, struct dirent *dir, iserror_t *error, stacktogo_t *st);
void create_mini_tab(nb_t *nb);
void check_file_error(char *file, struct dirent *t, char *name, stacktogo_t *st, nb_t *nb, iserror_t *error);
void print_debug(nb_t *nb, stacktogo_t *st);
char *my_strcat(char *dest, char *src);
nb_t *unstack(struct stacktogo *stackToDepile);
char *read_map(char *av);
void help_mode();
