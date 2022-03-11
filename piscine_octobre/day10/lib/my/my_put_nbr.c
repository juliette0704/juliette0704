/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** task
*/

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb < 0) {
        nb *= -1;
        my_putchar(45);
    }
    for (int i = count_digits(nb); i > 0; i--) {
        my_putchar((nb / power(10, i - 1) % 10) + 48);
    }
    return(0);
}
