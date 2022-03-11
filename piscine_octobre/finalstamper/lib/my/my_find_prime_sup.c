/*
** EPITECH PROJECT, 2021
** MY FIND PRIME SUP
** File description:
** Returns the smallest prime number greater than n
*/

#include <unistd.h>
#include <stdlib.h>

void my_putchar(char c);

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int found = 0;
    int i = nb;
    int number = -1;
    while (found == 0) {
        if (my_is_prime(i) == 1) {
            found = 1;
            number = i;
        }
        i++;
    }
    return (number);
}
