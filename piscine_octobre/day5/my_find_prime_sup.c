/*
** EPITECH PROJECT, 2021
** my_find_prime_sup.c
** File description:
** task
*/

int my_find_prime_sup(int nb)
{
    int res2, res3, res5;

    if (nb == 1)
        return (2);
    if (nb == 5 || nb == 2 || nb == 3)
        return (nb);
    if (nb == 0)
        return (0);
    if (nb < 0)
        return (0);
    if (nb != 0) {
        res2 = nb % 2;
        res3 = nb % 3;
        res5 = nb % 5;
        if (res2 == 0 || res3 == 0 || res5 == 0)
            return (my_find_prime_sup(nb + 1));
        else
            return (nb);
    }
    return (0);
}
