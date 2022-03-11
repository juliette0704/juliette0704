/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** lib
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#ifndef MY_H_
    #define MY_H_

int char_to_int(char *str);
int my_strlen(char const *str);
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
char **create_square(char**);
char **initial_tab(char *pos, char **mytab, char **enemytab);
void print_square(char **tab);
void creat_boat(char size, char firstland[2], int horizontal, char **mytab);
void tester(char **mytab);
void connect(char **av, struct sigaction, char **mytab, char**);
void play_sig(int signal, siginfo_t *info, void*);
int verify_touch(int, int, char **map);
void signal_call(int signal, siginfo_t *info, void*);
int check_user_entry(void);
int connecting(int ac,char **av,char **mytab,char **enemytab,struct sigaction actionsig);
int read_pos(char *av, char **mytab, char **enemytab);
int check_win(char **tab, int win);
void send_result(int touch);
void sendAttack(void);
void send_winner(void);
void first_screen(void);
int play_round(int ac, char **mytab, char **enemytab, int player);
void player_standby(int ac, int player, char **mytab, int touch);

#endif /* !MY_H_ */

