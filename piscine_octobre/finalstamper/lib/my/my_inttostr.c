/*
** EPITECH PROJECT, 2021
** my_inttostr
** File description:
** Convert int to str (1 digit max)
*/

char *my_inttostr(int num)
{
    char *p = (char *) malloc(128);
    *p = 0;
    if (num < 0) {
        do {
            *--p = '0' - num % 10;
        } while ((num /= 10) != 0);
        *--p = '-';
    } else {
        do {
            *--p = '0' + num % 10;
        } while ((num /= 10) != 0);
    }
    return p;
}
