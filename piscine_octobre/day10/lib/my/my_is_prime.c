/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** task
*/

int my_is_prime(int nb)
{
    int res2;
    int res3;
    int res5;

    if (nb == 5 || nb == 2 || nb == 3)
        return (1);
    if (nb == 0)
        return (0);
    if (nb < 0)
        return (0);
    if (nb != 0) {
        res2 = nb % 2;
        res3 = nb % 3;
        res5 = nb % 5;
        if (res2 == 0 || res3 == 0 || res5 == 0)
            return (0);
         else 
             return (1);
    }
        return (0);
}
