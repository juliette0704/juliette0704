/*
** EPITECH PROJECT, 2021
** MY COMPUTE SQUARE ROOT
** File description:
** Returns the square root of a number if whole number
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

void my_put_digits(int nb);

void my_put_nbr(int nb);

int square_root_rec(int nb, int mid)
{
    if ((mid * mid < nb) && ((mid + 1) * (mid + 1) > nb)) {
        return (0);
    }
    if (mid * mid == nb) {
        return (mid);
    }
    if (mid * mid < nb) {
        return (square_root_rec(nb, mid + 1));
    }
    return (square_root_rec(nb, mid - 1));
}

int my_compute_square_root(int nb)
{
    return (square_root_rec(nb, nb / 2));
}
