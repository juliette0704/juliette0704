/*
** EPITECH PROJECT, 2021
** edit_stack.c
** File description:
** dante
*/

#include "generator.h"

int check_errors(int x, int y, int v)
{
    // if ((ac < 3) && (ac > 4))
    //     return (84);
    if ((x < 48 || x > 57) && (y < 48 || y > 57))
        init_maze;
    else
        return (84);
    
}