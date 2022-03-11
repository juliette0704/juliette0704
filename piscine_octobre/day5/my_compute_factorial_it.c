/*
** EPITECH PROJECT, 2021
** my_compute_factorial_rec.c
** File description:
** task
*/

int  my_compute_factorial_it(int nb)
{
    int a = 1;

    if (nb < 0 || nb > 12) {
        a = 0;
    }
    while (nb >= 1) {
        a = a * nb;
        nb = nb -1;
    }
    return (a);
}
