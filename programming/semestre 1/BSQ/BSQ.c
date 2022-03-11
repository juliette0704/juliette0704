/*
** EPITECH PROJECT, 2021
** BSQ.c
** File description:
** bsq
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "include/my.h"

typedef struct square square;
struct square
{
    int x;
    int y;
    int size;
};

void map(char *);
int *nb_line(char *tot, int size);
int *nb_columns(char *tot, int size);
square *createSquare(square*, char** array, int*, int*);
void designSquare(square*, char** array);
void printArray(char** array, int* lines, int* cols);
int open_read(char **av);

square* createSquare(square *newsquare, char** array, int* col, int* lines)
{
    int size = 0;
    int x = newsquare->x, y = newsquare->y;
    int k = x, l = y;
    if (array[y][x] == 'o') {
        newsquare->size = 0;
        return newsquare;
    } else {
			while (array[l][k] != 'o' && k < *col) {           
                size++; 
                k++;
                for (int count = 1; count != size; count++) {                
                    k = x;
                    while (k != x + size) {
                        if (l + count >= *lines)
                            goto fin;
                        else {
                            if (array[l + count][k] == 'o' || k == *col) goto fin;
                            else k++;
                        }
                    }
                }
            newsquare->size = size;
            }
        fin:
        return newsquare; 
    }
}

void printArray(char** array, int* lines, int* cols)
{
    for (int j = 0; j < *lines; j++) {
        for (int i = 0; i < *cols; i++) {
            my_putchar(array[j][i]);
        }
        my_putchar('\n');
    }
}

void designSquare(square* theWinner,char** array)
{
    
    for (int j = 0; j < theWinner->size; j++) {
        for (int i = 0; i < theWinner->size; i++) {
            array[theWinner->y + j][theWinner->x + i] = 'x';
        }
    }
}

int open_read(char **av)
{
    struct stat buf;
    stat(av[1], &buf);
    int size = buf.st_size;
    int n = 1;
    char max[size];
    int fd = 0;
    fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        write(2, "ERROR", 5);
        return 84;
    }
    n = read(fd, max, size);
    map(max);
    return 0;
}

int *nb_line(char *tot, int size)
{
    int *lines = malloc(sizeof(int));
    *lines = 0;
        
    for (int i = 0; tot[i] != '\0'; i++) {
        if(tot[i] == '\n') *lines += 1;
    }
    *lines -= 1;
    return lines; 
}

int *nb_columns(char *tot, int size)
{
    int *columns = malloc(sizeof(int));
    int i = 0;
    *columns = 0;    
     while (tot[i] != '\n')
        i++;
    i += 1;
    for (; tot[i] != '\n'; i++)
        *columns += 1;
    return columns;
}

void map(char *max)
{
    int y = 0, x = 0, i = 0;
    int size = my_strlen(max);
    int *nbcolumns = malloc(sizeof(int));
    nbcolumns = nb_columns(max, size);
    int line = 0;
    int *nbline = malloc(sizeof(int));
    nbline = nb_line(max, size);
    char **array = (char**)malloc(*nbline * sizeof(char*));
    for (int count = 0; count < *nbline; count++)
        array[count] = (char*)malloc(*nbcolumns*sizeof(char));
    square *largestsquare = malloc(sizeof(*largestsquare));
    square *newsquare = malloc(sizeof(*newsquare));
    largestsquare->size = 0;
    while (max[i] != '\n')
        i++;
    i++;
    while (y != *nbline) {
        while (max[i] != '\n') {
            array[y][x] = max[i];
            x++;
            i++;
        }
        x = 0;
        y++;
        i++;
    }
    for (y = 0; y != *nbline; y++) {
        for (x = 0; x != *nbcolumns; x++) {
            newsquare->x = x;       
            newsquare->y = y;
            newsquare->size = 0;
            newsquare = createSquare(newsquare, array, nbcolumns, nbline);
            if (largestsquare->size < newsquare->size) {
                largestsquare->x = newsquare->x;
                largestsquare->y = newsquare->y;
                largestsquare->size = newsquare->size; }
            if (largestsquare->size == newsquare->size) {
                largestsquare->x = largestsquare->x;
                largestsquare->y = largestsquare->y;
                largestsquare->size = largestsquare->size; }
        }
    }
    designSquare(largestsquare, array);
    printArray(array, nbline, nbcolumns);
    free(array);
}

int main(int ac, char **av)
{
    open_read(av);
}
