/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** square
*/

#include <ncurses.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>


#ifndef MY_H_
    #define MY_H_

int my_strlen(char const *str);
int sizecol(char *str);
int sizeline(char *str);
int read_map(char **av);
int read_map(char **av);
int init_game(char *map);
bool verification_map(char *map);
int play(char *map);
char **str_to_word_array(char *chaine);

#endif /* !MY_H_ */