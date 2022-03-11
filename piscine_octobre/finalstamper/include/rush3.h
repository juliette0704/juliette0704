/*
** EPITECH PROJECT, 2021
** MY H
** File description:
** Contains all prototypes
*/

#ifndef MY_H_
    #define MY_H_
    
char *my_inttostr(int num);

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

void my_swapstr(char **a, char **b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

void my_sort_int_array(int *tab, int size);

int my_compute_power_rec(int nb, int power);

int my_compute_square_root(int nb);

int my_is_prime(int nb);

int my_find_prime_sup(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strupcase(char *str);

char *my_strlowcase(char *str);

char *my_strcapitalize(char *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_show_word_array(char * const *tab);

int square_root_rec(int nb, int mid);

int is_prime_rec(int nb, int i);

int my_put_digits(int nb);

int my_atoi(char const *str, int negatives);

int my_chartoint(char str);

int my_strtoint(char *str);

#endif
