/*
** EPITECH PROJECT, 2021
** myh
** File description:
** Contains all prototypes
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
int my_isneg(int nb);
void my_swap(int *a, int *b);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_getnbr(char const *str);
char *my_revstr(char *str);
int my_showstr(char const *str);
void my_put_unsigned(va_list nb1);
long long count_digitslong(long long nb);
void my_putchar2(va_list c1);
void convert_dec_hexa_maj2(va_list nb1);
void convert_dec_hexa2(va_list nb1);
void my_putstr2(va_list);
void my_put_nbr2(va_list nb1);
int my_strlen(char const *str);
int my_printf(char *n ,...);
int main(void);

#endif
