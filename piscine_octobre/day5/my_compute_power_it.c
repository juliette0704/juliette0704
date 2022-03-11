/*
** EPITECH PROJECT, 2021
** my_compute_power_it.c
** File description:
** task
*/

int my_compute_power_it(int nb, int p)
{
    int a = 1;
    int result = nb;
    
    if (p < 0)
        return (0);
    if (p == 0) {
        return (1);
    }
    while (a < p) {
        result = result * nb;
        a = a + 1;
    }
    return (result);
}
