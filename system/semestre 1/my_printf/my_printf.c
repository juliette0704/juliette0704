/*
** EPITECH PROJECT, 2021
** printf.c
** File description:
** printf
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int convert_dec_hexa(int nb);
int convert_dec_hexa_maj(int nb);
void convert_dec_octal(va_list nb1);
int count_digits2(int nb);
int power2(int a, int b);
int my_strlen(char const *str);
void my_putchar2(va_list);
void my_put_unsigned(va_list nb1);
long long count_digitslong(long long nb);
long long powerlong(int a, int b);
void convert_dec_hexa_maj2(va_list nb1);
void convert_dec_hexa2(va_list nb1);
void my_putstr2(va_list str1);
void my_put_nbr2(va_list nb1);
int my_strlen(char const *str);
int main(void);

void address(va_list nb1)
{
    my_putstr("0x");
    convert_dec_hexa2(nb1);
}

void rien(va_list nb)
{
    return ;
}


int pointeur(char *n, int i, va_list arg)
{
    int o = 0;
    char *t = "cdsoxXiupnC$";
    void (*p[11])(va_list);
    for (; n[i] != t[o]; o++); 
    p[0] = my_putchar2;
    p[1] = my_put_nbr2;
    p[2] = my_putstr2;
    p[3] = convert_dec_octal;
    p[4] = convert_dec_hexa2;
    p[5] = convert_dec_hexa_maj2;
    p[6] = my_put_nbr2;
    p[7] = my_put_unsigned;
    p[8] = address;
    p[9] = rien;
    p[10] = my_putchar2;
    p[11] = rien;
    (*p[o])(arg);
    if (t[i] == 11) return 84;
    return (0);
}

int my_printf(char *n ,...)
{
    int i = 0, h = 0, o = 0;
    va_list arg;
    va_start(arg, n);

    for ( ; n[i] != '\0'; i++) {
        if (n[i] == '%') {
            i++;
            if (n[i] == ' ' || n[i] == 't') i++;
            if (n[i] == 'j' || n[i] == '0') i++;
            if (n[i] == 'h' && n[i++] == 'h') i++;
            if (n[i] == '#') {
                i++;
                if(n[i] == 'o') my_putchar('0');
                if(n[i] == 'x') my_putstr("0x");
                }
            if(n[i] == '%') {
                my_putchar('%');
                return 0;
            }
            if(n[i] == '+') {
                i++;
                if (n[i] == 'd') {
                    h = va_arg(arg, int);
                    if (h > 0) my_putchar('+');
                    my_put_nbr(h);
                } else pointeur(n, i, arg);
            } else {
                pointeur(n, i, arg);
            }
        } else my_putchar(n[i]);
    }
    va_end(arg);
}

int main(void)
{
    my_printf("%d", 5);
}
