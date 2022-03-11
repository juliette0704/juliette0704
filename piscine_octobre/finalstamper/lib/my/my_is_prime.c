/*
** EPITECH PROJECT, 2021
** MY IS PRIME
** File description:
** Returns 1 if number is prime, 0 if not
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int is_prime_rec(int nb, int i)
{
    if (nb < 2) {
        return (0);
    }
    if (nb == 2) {
        return (1);
    }
    if (nb % i == 0) {
        return (0);
    }
    if (i * i > nb) {
        return (1);
    }
    return (is_prime_rec(nb, i + 1));
}

int my_is_prime(int nb)
{
    return (is_prime_rec(nb, 2));
}
