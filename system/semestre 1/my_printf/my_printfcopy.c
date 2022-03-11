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
void my_putchar(char c );
int my_putstr(char const *str);
int my_put_nbr(int nb);

void my_putchar(char c )
{
    write(1, &c, 1);
}
void my_putchar2(va_list c1)
{
    int c = va_arg(c1, int);
    write(1, &c, 1);
}
int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}
void my_putstr2(va_list str1)
{
    char *str = va_arg(str1, char *);

    write(1, str, my_strlen(str));
}
int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }  
}

void my_put_unsigned(va_list nb1)
{
    long long nb = va_arg(nb1, long long);

    if (nb == 0) {
        my_putchar('0');
        return ;
    }
    if (nb < 0) {
        nb *= -1;
        nb = nb - 4294967296;
        return ;
    }
    for (int i = count_digitslong(nb); i > 0; i--) {
        my_putchar((nb / powerlong(10, i - 1) % 10) + 48);
    }
}

int power2(int a, int b)
{
    int result = a;

    if (b == 0) {
        return (1);
    }
    for (int i = 0; i < b - 1; i++) {
        result *= a;
    }
    return (result);
}
long long powerlong(int a, int b)
{
    int result = a;

    if (b == 0) {
        return (1);
    }
    for (int i = 0; i < b - 1; i++) {
        result *= a;
    }
    return (result);
}

int count_digits2(int nb)
{
    int count = 0;
    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}

void my_put_nbr2(va_list nb1)
{
    int nb = va_arg(nb1, int);

    if (nb == 0) {
        my_putchar('0');
        return ;
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    for (int i = count_digits2(nb); i > 0; i--) {
        my_putchar((nb / power2(10, i - 1) % 10) + 48);
    }
}

int power(int a, int b)
{
    int result = a;

    if (b == 0) {
        return (1);
    }
    for (int i = 0; i < b - 1; i++) {
        result *= a;
    }
    return (result);
}

int count_digits(int nb)
{
    int count = 0;
    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar(45);
    }
    for (int i = count_digits(nb); i > 0; i--) {
        my_putchar((nb / power(10, i - 1) % 10) + 48);
    }
    return(0);
}

long long count_digitslong(long long nb)
{
    long long count = 0;
    while (nb != 0) {
        nb = nb / 10;
        count++;
    }
    return (count);
}

void convert_dec_octal(va_list nb1)
{
    int nb = va_arg(nb1, int);
    //int nb = nb1;
    int octal[50];
    int i = 1;
    int j = 0;
 
    while (nb != 0)
    {
        octal[i++] = nb % 8;
        nb /= 8;
    }
    for (j = i - 1; j > 0; j--)
        my_put_nbr(octal[j]);
}
void convert_dec_hexa2(va_list nb1)
{
    int i = 1;
    int j = 0;
    int temp = 0;
	int nb = 0;
    nb = va_arg(nb1, int);
	char *hex = malloc(sizeof(*hex));
	if (nb < 0) {
		my_putstr("ffffff");
		nb = nb * (-1);
	}
	while (nb != 0) {
		temp = nb % 16;
		if( temp <= 9)
		    temp += 48;
        else
		    temp += 87;
		hex[i++] = temp;
		nb = nb / 16;
	}
	for (j = i -1 ;j> 0;j--)
        my_putchar(hex[j]);
}

int convert_dec_hexa(va_list arg)
{
    int i = 1;
    int j = 0;
    int temp = 0;
	int nb = va_arg(arg ,int);
	char *hex = malloc(sizeof(*hex));
	if (nb < 0) {
		my_putstr("ffffff");
		nb = nb * (-1);
	}
	while (nb != 0) {
		temp = nb % 16;
		if( temp <= 9)
		    temp += 48;
        else
		    temp += 87;
		hex[i++] = temp;
		nb = nb / 16;
	}
	for (j = i - 1 ; j > 0; j--)
        my_putchar(hex[j]);
	return 0;
}



void convert_dec_hexa_maj2(va_list nb1)
{
    int nb = va_arg(nb1, int);
    int i = 1;
    int j = 0;
    int temp = 0;
	char *hex = malloc(sizeof(*hex));
	if (nb < 0) {
	my_putstr("FFFFFF");
	nb = nb * (-1);
	}
	while (nb != 0) {
		temp = nb % 16;
		if( temp <= 9)
		    temp += 48;
        else
		    temp += 55;
		hex[i++] = temp;
		nb = nb / 16;
	}
	for (j = i -1 ;j> 0;j--)
        my_putchar(hex[j]);
}

int convert_dec_hexa_maj(int nb)
{
    int i = 1;
    int j = 0;
    int temp = 0;
	char *hex = malloc(sizeof(*hex));
	if (nb < 0) {
	my_putstr("FFFFFF");
	nb = nb * (-1);
	}
	while (nb != 0) {
		temp = nb % 16;
		if( temp <= 9)
		    temp += 48;
        else
		    temp += 55;
		hex[i++] = temp;
		nb = nb / 16;
	}
	for (j = i -1 ;j> 0;j--)
        my_putchar(hex[j]);
	return 0;
}



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