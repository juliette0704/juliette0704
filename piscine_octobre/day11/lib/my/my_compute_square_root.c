/*
** EPITECH PROJECT, 2021
** my_compute_square_root.c
** File description:
** task
*/

int my_compute_square_root(int nb)
{
    int a = 1;
    int res = 1;
    if (nb <= 0)
        return (0);
    while (res < nb) {
        a++;
        res = a * a;
    }
    if (a * a != nb)
        return (0);
    return (a);
}
