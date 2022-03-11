/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"
#include "soko.h"

int is_it_win(char **map)
{
    int x = 0;
    int y = 0;
    while (map[x] != NULL) {
        if (map[x][y] == 'X') {
            return 0;
        }
        y++;
        if (map[x][y] == '\0') {
            x++;
            y = 0;
        }
    }
    return 1;
}

void print_double_array(char **array, int nbcol, int line)
{
    int j = 0;
    int i = 0;
    if (line == 1) {
        for (; i < line; i++) {
            printw("%s", array[i]);
            j++;
            if (j < nbcol - 2)
                printw("\n");
        }
    } else {
        for (; i < line - 1; i++) {
            printw("%s", array[i]);
            j++;
            if (j < nbcol - 2)
                printw("\n");
        }
    }
}

char **moov_up(char **map, int col, int line)
{
    int x = 0;
    int y = 0;
    while (map[x] != NULL) {
        if (map[x][y] == 'P') {
            break;
        }
        y++;
        if (map[x][y] == '\0') {
            x++;
            y = 0;
        }
    }
    if (x == 1)
        map[x][y] = map[x][y];
    else {
        map[x][y] = ' ';
        x--;
        map[x][y] = 'P';
    }
    return map;
}

char **moov_down(char **map, int col, int line)
{
    int x = 0;
    int y = 0;
    while (map[x] != NULL) {
        if (map[x][y] == 'P') {
            break;
        }
        y++;
        if (map[x][y] == '\0') {
            x++;
            y = 0;
        }
    }
    if (x == col - 4)
        map[x][y] = map[x][y];
    else {
        map[x][y] = ' ';
        x++;
        map[x][y] = 'P';
    }
    return map;
}

char **moov_left(char **map, int col, int line)
{
    int x = 0;
    int y = 0;
    while (map[x] != NULL) {
        if (map[x][y] == 'P') {
            break;
        }
        y++;
        if (map[x][y] == '\0') {
            x++;
            y = 0;
        }
    }
    if (y == 1)
        map[x][y] = map[x][y];
    else {
        map[x][y] = ' ';
        y--;
        map[x][y] = 'P';
    }
    return map;
}

int moov_right(char **map, int col, int line, int y, int x)
{
    if (map[x][y] == '#')
        y = y;
    else

        // y++;
    return y;
}

char *erase_p(char **map)
{
    int x = 0;
    int y = 0;
    while (map[x] != NULL) {
        if (map[x][y] == 'P') {
            break;
        }
        y++;
        if (map[x][y] == '\0') {
            x++;
            y = 0;
        }
    }
}

int verif_map_right(char **map, int x, int y, int col)
{
    int j = 0;
    obj_t *object = malloc(sizeof(obj_t));
    object->bord = 0;
    object->cage = 0;
    j = y + 1;
    if (map[x][j] == '#')
        return 1;
    else if (map[x][j] == 'X')
        return 2;
    else
        return 0;
}

int verif_map_left(char **map, int x, int y, int col)
{
    int j = 0;
    obj_t *object = malloc(sizeof(obj_t));
    object->bord = 0;
    object->cage = 0;
    j = y - 1;
    if (map[x][j] == 'X')
        return 2;
    else if (map[x][j] == '#')
        return 1;
    else
        return 0;
}

int verif_map_down(char **map, int x, int y, int col)
{
    int j = 0;
    obj_t *object = malloc(sizeof(obj_t));
    object->bord = 0;
    object->cage = 0;
    j = x + 1;
    if (map[j][y] == '#')
        return 1;
    else if (map[j][y] == 'X')
        return 2;
    else
        return 0;
}

int verif_map_up(char **map, int x, int y, int col)
{
    int j = 0;
    obj_t *object = malloc(sizeof(obj_t));
    object->bord = 0;
    object->cage = 0;
    j = x - 1;
    if (map[j][y] == '#')
        return 1;
    else if (map[j][y] == 'X')
        return 2;
    else
        return 0;
}

int verif_map_down_with_cage(char **map,int x,int y,int sizeofcol)
{
    int j = x + 2;
    if (map[j][y] == '#' || map[j][y] == 'X')
        return 2;
    else
        return 0;
}

int verif_map_up_with_cage(char **map,int x,int y,int sizeofcol)
{
    int j = x - 2;
    if (map[j][y] == '#' || map[j][y] == 'X')
        return 2;
    else
        return 0;
}

int verif_map_left_with_cage(char **map,int x,int y,int sizeofcol)
{
    int j = y - 2;
    if (map[x][j] == '#' || map[x][j] == 'X')
        return 2;
    else
        return 0;
}

int verif_map_right_with_cage(char **map,int x,int y,int sizeofcol)
{
    int j = y + 2;
    if (map[x][j] == '#' || map[x][j] == 'X')
        return 2;
    else
        return 0;
}

bool verif_winner(char **map)
{
    int x = 0;
    int y = 0;
    while (map[x] != NULL) {
        if (map[x][y] == 'O') {

        }
        y++;
        if (map[x][y] == '\0') {
            x++;
            y = 0;
        }
    }
    return true;
}

void case_of_b(arraymap_t *arraymap, int sizeofcol)
{
    if (verif_map_down(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 0)
        arraymap->x++;
    else if (verif_map_down(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2) {
        if (verif_map_down_with_cage(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2)
            arraymap->x = arraymap->x;
        else {
            arraymap->x++;
            int j = arraymap->x + 1;
            arraymap->map[arraymap->x][arraymap->y] = ' ';
            arraymap->map[j][arraymap->y] = 'X';
        }
    }
}

// int verif_defeat(arraymap_t *map)
// {
//     int x = map->x + 2;
//     int y = map->y + 2;

//     if (map->map[map->x][map->y])
// }

void case_of_a(arraymap_t *arraymap, int sizeofcol)
{
    if (verif_map_up(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 0)
        arraymap->x--;
    else if (verif_map_up(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2) {
        if (verif_map_up_with_cage(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2)
            arraymap->x = arraymap->x;
        else {
            arraymap->x--;
            int j = arraymap->x - 1;
            arraymap->map[arraymap->x][arraymap->y] = ' ';
            arraymap->map[j][arraymap->y] = 'X';
        }
    }
}

void case_of_d(arraymap_t *arraymap, int sizeofcol)
{
    if (verif_map_left(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 0)
        arraymap->y--;
    else if (verif_map_left(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2) {
        if (verif_map_left_with_cage(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2)
            arraymap->y = arraymap->y;
        else {
            arraymap->y--;
            int j = arraymap->y - 1;
            arraymap->map[arraymap->x][arraymap->y] = ' ';
            arraymap->map[arraymap->x][j] = 'X';
            }
    }
}

void case_of_c(arraymap_t *arraymap, int sizeofcol)
{
    if (verif_map_right(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 0)
        arraymap->y++;
    else if (verif_map_right(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2) {
        if (verif_map_right_with_cage(arraymap->map, arraymap->x, arraymap->y, sizeofcol) == 2)
            arraymap->y = arraymap->y;
        else {
            arraymap->y++;
            int j = arraymap->y + 1;
            arraymap->map[arraymap->x][arraymap->y] = ' ';
            arraymap->map[arraymap->x][j] = 'X';
        }
    }
}

char **remove_p(arraymap_t *arraymap)
{
    while (arraymap->map[arraymap->x] != NULL) {
        if (arraymap->map[arraymap->x][arraymap->y] == 'P') {
            break;
        }
        arraymap->y++;
        if (arraymap->map[arraymap->x][arraymap->y] == '\0') {
            arraymap->x++;
            arraymap->y = 0;
        }
    }
    arraymap->map[arraymap->x][arraymap->y] = ' ';
    return arraymap->map;
}

int play(char *map)
{
    arraymap_t *arraymap = malloc(sizeof(arraymap_t));
    int sizeofcol = sizecol(map);
    int sizeofline = sizeline(map);
    int sizetot = my_strlen(map);
    arraymap->x = 0;
    arraymap->y = 0;
    char enlargeterm[30] = "ENLARGED THE TERMINAL";
    arraymap->map = str_to_word_array(map);
    arraymap->map = remove_p(arraymap);
    while (1) {
        curs_set(0);
        noecho();
        initscr();
        clear();
        if (LINES < sizeofline || COLS < sizeofcol)
            mvprintw(LINES/2, (COLS / 2) - 22, enlargeterm);
        else {
            print :
            print_double_array(arraymap->map, sizeofcol, sizeofline);
            mvprintw(arraymap->x, arraymap->y, "P");
            switch (getch()) {
                case 'C' :
                if (arraymap->y != sizeofcol - 2) {
                    case_of_c(arraymap, sizeofcol);
                        if (verif_winner(arraymap->map) == true)
                            goto end;
                }
                        clear();
                        goto print;
                        break;
                case 'D' :
                if (arraymap->y != 0) {
                case_of_d(arraymap, sizeofcol);
                    if (verif_winner(arraymap->map) == true)
                        goto end;
                    // if (verif_defeat(arraymap) == true)
                    //     return 84;
                }
                    clear();
                    goto print;
                    break;
                case 'A' :
                if (arraymap->x != 0) {
                    if (sizeofline != 1) {
                        case_of_a(arraymap, sizeofcol);
                    if (verif_winner(arraymap->map) == true)
                        goto end;
                    // if (verif_defeat(arraymap->map) == true)
                    //     return 84;
                    }
                }
                    clear();
                    goto print;
                    break;
                case 'B' :
                if (arraymap->y != sizeofline - 1) {
                    if (sizeofline != 2) {
                        case_of_b(arraymap, sizeofcol);
                    if (verif_winner(arraymap->map) == true)
                        goto end;
                }
                    clear();
                    goto print;
                    break;
                }
            }
        refresh();
        }
    }
    end :
    endwin();
}

int init_game(char *map)
{
    int i = verification_map(map);
    if (i == 0)
        return 84;
    else
        play(map);
}

int main(int ac, char **av)
{
    if (read_map(av) == 1)
        return 84;
}
