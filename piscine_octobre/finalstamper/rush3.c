/*
** EPITECH PROJECT, 2021
** RUSH 3
** File description:
** Rush 3 (final stumper)
*/

#include <unistd.h>
#include "include/rush3.h"

#define BUFF_SIZE (2048)

void rush3(char *buff)
{
    int i = 0, x = 0, y = 0, which = 0, chr = read(0, buff, BUFF_SIZE);
    for (; buff[i] != '\0'; i++) {
        chr = read(0, buff, BUFF_SIZE);
        if (buff[i] == '\n') y += 1; if (buff[i] == '\n' && x == 0) x = i;
        if (buff[i] == 'o') which = 1;
        if (buff[i] == '/' || buff[i] == '*') which = 2;
        if (i == 0 && buff[i] == 'B') which = 345;
        if (buff[i] == '\n' && which == 0 && buff[i - 1] == 'A') which = 3;
        if (buff[i] == '\n' && which == 0 && buff[i - 1] == 'C') which = 4;
    }
    if (buff[i - 2] == 'A') which = 5;
    char *whichstr = my_inttostr(which);
    for (i = 0; i < my_strlen(whichstr); i++) {
        my_putstr("[rush1-"); my_putchar(whichstr[i]); my_putstr("] ");
        my_put_nbr(x); my_putchar(' '); my_put_nbr(y);
        if (which == 345 && whichstr[i] != '5') my_putstr(" || ");
    }
}

int main(void)
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;
    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0) return (84);
    rush3(buff);
    my_putchar('\n');
    return (0);
}
