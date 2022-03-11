/*
** EPITECH PROJECT, 2021
** vrai.c
** File description:
** test
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

typedef struct s_num {
    char    *value;
    int     idx;
    int     size;
    int     neg;
} t_num;

void my_putchar1(char c)
{
	write(1, &c, 1);
}

int check_neg(t_num *num1, t_num *num2)
{
    if (num1->value[0] == '-') {
        num1->neg = 1;
        num1->value++;
    }
    if (num2->value[0] == '-') {
        num2->neg = 1;
        num2->value++;
    }
    if (num1->neg == 1 && num2->neg == 0 || num1->neg == 0 && num2->neg == 1)
        return -1;
    return 0;
}

int positiv(t_num *num1, t_num *num2)
{
    int i = 0;
    int value = 0;
    int ret = 0;
    char *result;
    
    if (check_neg(num1, num2) == -1)
        return -1;
    if (num1->size < num2->size) {
        my_swap(&num1->value, &num2->value);
        num1->size = my_strlen(num1->value);
        num2->size = my_strlen(num2->value);
    }
    result = malloc(sizeof(char) * num1->size + num2->size);
    num1->value = my_revstr(num1->value);
    num2->value = my_revstr(num2->value);
    for (; num1->value[i] != '\0'; i++) {
        if (i < num2->size) {
            value = (num2->value[i] - '0') + (num1->value[i] - '0') + ret;
        }
        else
            value = (num1->value[i] - 48) + ret;
        ret = 0;
        if (value > 9) {
            value = value - 10;
            ret = 1;
        }
        result[i] = (value + 48);
    }
    if (ret == 1) {
        result[i] = '1';
        i++;
    }
    result[i] = '\0';
    my_revstr(result);

    if (num1->neg == 1 && num2->neg == 1) {
        my_putchar('-');
        my_putstr(result);
        my_putchar('\n');
    } else {
       my_putstr(result);
       my_putchar('\n');
    }
    return 0;
}

int main (int ac, char **av)
{
    t_num num1;
    t_num num2;

    if (ac != 3){
        my_putstr("Missing Argument(s)");
        my_putchar('\n');
        return 1;
    }    
    num1.value = av[1];
    num1.size = my_strlen(av[1]);
    num2.value = av[2];
    num2.size = my_strlen(av[2]);
    positiv(&num1, &num2);
}
