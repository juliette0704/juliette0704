/*
** EPITECH PROJECT, 2021
** convert_dec_hexa_maj2.c
** File description:
** task
*/

#include <stdlib.h>
#include <stdarg.h>

void my_putchar(char c);
int my_putstr(char const *str);

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