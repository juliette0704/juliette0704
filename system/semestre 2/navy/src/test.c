/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** navy
*/

#include "my.h"
#include "navy.h"

extern posxy_t *posxy1;

void connect(char **av, struct sigaction actionsig, char **mytab, char **enemytab)
{
    my_putstr("waiting for enemy connection...\n\n");
    actionsig.sa_sigaction = signal_call;
    actionsig.sa_flags = SA_SIGINFO;
    sigaction(12, &actionsig, NULL);
    while (posxy1->enemypid == 0) {};
    my_putstr("enemy connected\n\n");
    read_pos(av[1], mytab, enemytab);
    return ;
}

void play_sig(int signal, siginfo_t *info, void*nono)
{
    if (signal == 10) posxy1->count++;
    if (signal == 12 && posxy1->count < 9) {
        if (posxy1->col == 0) {
            posxy1->col = posxy1->count;            
            posxy1->count = 0;
        } else
            posxy1->line = posxy1->count; }
    if (signal == 12 && posxy1->count == 9) {
        posxy1->hit = 1;
        posxy1->count = 0; }
    if (signal == 12 && posxy1->count == 10) {
        posxy1->hit = 2;
        posxy1->count = 0; }
    if (signal == 12 && posxy1->count == 12) {
        posxy1->winner = 0;
        posxy1->count = 0; }
    if (signal == 12 && posxy1->count == 13) {
        posxy1->winner = 1;
        posxy1->count = 0; }
}

void sendAttack(void)
{
    int i = 0, j = 0;
    char c;
    size_t size = 2;
    do 
        getline(&posxy1->userentry, &size, stdin);
        while (check_user_entry()==1);
    for (int j = 0; j < posxy1->userentry[0] - (48 + 16); j++) {
        kill(posxy1->enemypid, 10);
        usleep(1);
    }
    my_putchar(posxy1->userentry[0]);
    my_put_nbr(posxy1->userentry[1] - 48);
    my_putstr(": ");
    kill(posxy1->enemypid, 12);
    usleep(1);
    for (int f = 0; f < posxy1->userentry[1] - 48; f++) {
        kill(posxy1->enemypid, 10);
        usleep(1); }
    kill(posxy1->enemypid, 12);
    return;
}

void send_result(int touch)
{
    if (touch == 0) {
        for (int i = 0; i < 9; i++) {
            kill(posxy1->enemypid, 10);
            usleep(1);
        }
    kill(posxy1->enemypid,12);
    }
    if (touch == 1) {
        for (int i = 0; i < 10; i++) {
            kill(posxy1->enemypid, 10);
            usleep(1);
        }
    kill(posxy1->enemypid, 12);
    }
}

int check_win(char **tab, int win)
{
    int y = 0;
    int x = 0;
    int flag = 1;
    while (y < 8) {
        while (x < 8) {
                if (tab[y][x] <= 8 && tab[y][x] > 0)
                    flag = 0;
            x++;
        }       
    y++;
    x = 0;
    }
    if (flag == 1)
        win = 1;
    else 
        win = 0;
    return win;
}
