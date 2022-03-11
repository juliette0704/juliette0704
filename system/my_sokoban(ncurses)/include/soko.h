/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** square
*/

typedef enum mapcharacter
{
    player,
    O,
    X,
    bord,
} map;

typedef struct col
{
    int colonmax;
} col_t;

typedef struct obj
{
    int bord;
    int cage;
} obj_t;

typedef struct arraymap
{
    char **map;
    int x;
    int y;
} arraymap_t;

typedef struct win
{
    int nbcage;
} win_t;