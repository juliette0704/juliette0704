/*
** EPITECH PROJECT, 2021
** navy.c
** File description:
** navy
*/

#include "my.h"
#include "navy.h"

posxy_t *posxy1;

void initialize_posxy(posxy_t *posxy1)
{
    posxy1->winner = 0;
    posxy1->line = 0;
    posxy1->col = 0;
    posxy1->count = 0;
    posxy1->whoseturn = 1;
    posxy1->hit = 0;
}

int check_user_entry(void)
{
    if (!(posxy1->userentry[0] <= 'H' && posxy1->userentry[0] >= 'A')) {
        my_putstr("wrong position\nattack: ");

        return 1;
    }
    if (!(posxy1->userentry[1] <= '8' && posxy1->userentry[1] >= '1')) {
        my_putstr("wrong position\nattack: ");
        return 1;
    }
    return 0;
}

void player_standby(int ac, int player, char **mytab, int touch)
{
    my_putstr("waiting for enemy's attack...\n");
    while(posxy1->col == 0 || posxy1->line == 0);
    touch = verify_touch(posxy1->col, posxy1->line, mytab);
    if (touch == 0) {
        my_putchar(posxy1->col + 64);
        my_putchar(posxy1->line + 48);
        my_putstr(": missed\n\n");
        mytab[posxy1->line - 1][posxy1->col - 1] = 111;
    }
    if (touch == 1) {
        my_putchar(posxy1->col + 64);
        my_putchar(posxy1->line + 48);
        my_putstr(": hit\n");
        mytab[posxy1->line - 1][posxy1->col - 1] = 120;
    }
    posxy1->winner = check_win(mytab, posxy1->winner);
    send_result(touch);
    send_winner();
    posxy1->col = 0;
    posxy1->line = 0;
}

int main(int ac, char **av)
{
    char **enemytab = (char**)malloc(8 * sizeof(char*));
    for (int count = 0; count < 8; count++)
        enemytab[count] = (char*)malloc(8 * sizeof(char));
    char **mytab = (char**)malloc(8 * sizeof(char*));
    for (int count = 0; count < 8; count++) 
        mytab[count] = (char*)malloc(8 * sizeof(char));
    struct sigaction actionsig;
    posxy1 = malloc(sizeof(*posxy1));
    initialize_posxy(posxy1);
    int player = 1;
    first_screen();
    connecting(ac, av, mytab, enemytab, actionsig);
    actionsig.sa_sigaction = play_sig;
    actionsig.sa_flags = SA_SIGINFO;
    sigaction(10, &actionsig, NULL);
    sigaction(12, &actionsig, NULL);
    play_round(ac, mytab, enemytab, player);
    if ((ac-1) == player) my_putstr("\nEnemy won\n");
    else 
        my_putstr("\nI won\n");
}