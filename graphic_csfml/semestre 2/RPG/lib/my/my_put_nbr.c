/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** task01
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int v = nb;
    int n = 1;

    if (v == 0)
        my_putchar('0');

    if (v < 0) {
        my_putchar ('-');
        v = v * (-1);
    }

    while ((v / n) != 0)
        n = (n * 10);
    n = n / 10;
    while (n != 0) {
        my_putchar('0' + (v / n));
        v = v % n;
        n = n / 10;
    }
    return 0;
}
