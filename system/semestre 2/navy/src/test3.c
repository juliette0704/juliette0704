/*
** EPITECH PROJECT, 2021
** test3.c
** File description:
** navy
*/

#include "my.h"
#include "navy.h"
extern posxy_t *posxy1;

void player_attack(char **enemytab)
{
    my_putstr("attack:");
    my_putchar(' ');
    sendAttack();
    while(posxy1->hit == 0 || posxy1->winner == 2);       
    if (posxy1->hit == 1) {
        my_putstr("missed\n");
        enemytab[(posxy1->userentry[1] - 48) - 1][(posxy1->userentry[0] - (48 + 16)) - 1] = 'o';
    }
    if (posxy1->hit == 2) {
        my_putstr("hit\n");
        enemytab[(posxy1->userentry[1] - 48) - 1][(posxy1->userentry[0] - (48 + 16)) - 1] = 'x';
    }
    posxy1->hit = 0;

}

int play_round(int ac, char **mytab, char **enemytab, int player)
{
    int roundcount = 0, touch = 0;
        while(posxy1->winner == 0) {
        posxy1->winner = 2;
        roundcount++;
        if ((ac-1) != player)
            player_standby(ac, player, mytab, touch);
        else player_attack(enemytab);
        if (player == 1) player = 2;
        else player = 1;
        if (roundcount % 2 == 0 || posxy1->winner == 1){
            my_putstr("\nmy positions:\n");
            print_square(mytab);
            my_putstr("\nenemy's positions:\n ");
            print_square(enemytab);
            my_putchar('\n');
        }
        posxy1->count = 0;
        posxy1->hit = 0;
    }
    return player;
}

void first_screen(void)
{
    my_putstr("my_pid: ");
    my_put_nbr(getpid());
    my_putchar('\n');
}
