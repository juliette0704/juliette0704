/*
** EPITECH PROJECT, 2021
** convert_dec_octal.c
** File description:
** my_put_unsigned
*/

#include <stdarg.h>
int my_put_nbr(int);

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