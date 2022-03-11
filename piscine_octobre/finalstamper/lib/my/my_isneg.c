/*
** EPITECH PROJECT, 2021
** MY ISNEG
** File description:
** Displays either N if the int. passed as param. is neg. or P if pos. or null
*/

#include <unistd.h>

int my_isneg(int nb)
{
    if (nb < 0) {
        return (0);
    } else {
        return (1);
    }
}
