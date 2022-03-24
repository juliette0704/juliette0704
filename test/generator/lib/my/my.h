/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** task03
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <time.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
char *my_int_to_str(int digits);
int char_to_int(char *str);

#endif /* MY_H_ */
