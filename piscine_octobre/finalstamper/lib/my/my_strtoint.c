/*
** EPITECH PROJECT, 2021
** STRTOINT
** File description:
** Convert str to int
*/

int my_chartoint(char str)
{
    int num = 0;
    num = num * 10 + (str - 48);
    return (num);
}

int my_strtoint(char *str)
{
    int num = 0;
    int i = 0;
    int j = my_strlen(str) - 1;
    int run = 1;
    while (run == 1) {
        num += (my_chartoint(str[j]) * my_compute_power_rec(10, i));
        i += 1;
        j -= 1;
        if (j < 0) run = 0;
    }
    return (num);
}