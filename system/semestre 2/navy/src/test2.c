/*
** EPITECH PROJECT, 2021
** test2.c
** File description:
** navy
*/

#include "my.h"
#include "navy.h"
extern posxy_t *posxy1;

int read_pos(char *av, char **mytab, char **enemytab)
{
    int n = 1;
    char max[1000];
    int fd = 0;
    fd = open(av, O_RDONLY);
    if (fd == -1) {
        write(2, "ERROR", 5);
        return 84;
    }
    n = read(fd, max, 1000);
    initial_tab(max, mytab, enemytab);
    return 0;
}

void signal_call(int signal, siginfo_t *info, void* nono)
{
    posxy1->enemypid = info->si_pid;
}

void send_winner(void)
{
   if (posxy1->winner == 0) {
        for (int i = 0; i < 12; i++) {
            kill(posxy1->enemypid, 10);
            usleep(1);
        }
        kill(posxy1->enemypid, 12);
        usleep(1);
    }
    if (posxy1->winner == 1) {
        for (int i = 0; i < 13; i++) {
            kill(posxy1->enemypid, 10);
            usleep(1);
        }
        kill(posxy1->enemypid, 12);
        usleep(1);
    }
}

int connecting(int ac,char **av,char **mytab,char **enemytab,struct sigaction actionsig)
{
    int p1pid = 0;
    if (ac == 2)
        connect(av, actionsig, mytab, enemytab);
    else if (ac == 3) {        
        p1pid = char_to_int(av[1]);
        posxy1->enemypid = p1pid;
        if (kill(p1pid, 12) == 0)
            my_putstr("successfully connected\n\n");
        else {
            my_putstr("error connecting");
            return 84;
        }
        read_pos(av[2], mytab, enemytab);
    } else
        return 84;
}
