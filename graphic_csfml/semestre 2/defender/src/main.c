/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "defender.h"
#include <math.h>

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        game_rules();
        return (0);
    } else
        init_the_game();
    return (0);
}
