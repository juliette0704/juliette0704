/*
** EPITECH PROJECT, 2021
** convert_dec_hexa.c
** File description:
** task
*/

#include <stdlib.h>
#include <stdarg.h>

int my_putstr(char const *str);
void my_putchar(char c);

int convert_dec_hexa(va_list arg)
{
    int i = 1;
    int j = 0;
    int temp = 0;
	int nb = 0;
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