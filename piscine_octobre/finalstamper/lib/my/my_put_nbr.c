/*
** EPITECH PROJECT, 2021
** MY PUT NBR
** File description:
** Displays the number given as a parameter
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_put_digits(int nb)
{
    if (nb >= 10) {
        my_put_digits(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar(45);
        my_put_digits(0 - nb);
    } else {
        my_put_digits(nb);
    }
    return (nb);
}
