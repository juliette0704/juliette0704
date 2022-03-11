/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** lib
*/

#ifndef MY_H_
    #define MY_H_
    
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <time.h>
    #include <SFML/System.h>
    #include <stdio.h>
    #include <math.h>
    #include "SFML/Audio.h"
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include "struct.h"

struct b *init_sprite(char *path);
void moov_bg(int x);
int init_rect(globale_t *all, speed_t *);
int moov_rect(globale_t *all, speed_t *);
int read_pos(int ac, char *av, globale_t *m);
void moov_sprite(globale_t *m, speed_t *speed, jump_t *);
int fall(globale_t *m, speed_t *speed, sfVector2f pos, jump_t *jumping, int);
sfText* init_score(sfVector2f position, int score, globale_t *m, sfText *text);
void print_sprite(globale_t *m, speed_t *v, score_t *);
void jumpe(globale_t *m, speed_t *speed, jump_t *jumping);
int init_rect_jump(globale_t *all, speed_t *speed);
turtle_t *sprite_turtle(globale_t *m);
int moov_rect_jump(globale_t *all, speed_t *speed);
globale_t init(globale_t m);
void my_putstr(char *str);
void menu(globale_t *m);
globale_t *run(globale_t *m, speed_t *v, int ac, score_t *s, jump_t *jump, char **av);
void play(globale_t *m, speed_t *v, int ac, score_t *s, jump_t *jump, char **av);
victory_t *sprite_victory(globale_t *);

#endif /* !MY_H_ */
