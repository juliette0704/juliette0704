/*
** EPITECH PROJECT, 2021
** convert_dec_hexa.c
** File description:
** task
*/

#include <stdarg.h>
#include <stdlib.h>

void my_putchar(char c);
int my_putstr(char const *str);

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