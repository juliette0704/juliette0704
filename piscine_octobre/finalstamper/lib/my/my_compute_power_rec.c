/*
** EPITECH PROJECT, 2021
** MY COMPUTE POWER REC
** File description:
** Returns np raised to the power p
*/

#include <unistd.h>
#include <stdlib.h>

int my_compute_power_rec(int nb, int power)
{
    if (power == 0) {
        return (1);
    } else if (power < 0) {
        return (0);
    }
    return (nb * my_compute_power_rec(nb, power - 1));
}
