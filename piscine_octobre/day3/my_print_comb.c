/*
** EPITECH PROJECT, 2021
** my_print_com.c
** File description:
** task
*/

int fonct(char* digit1, char* digit2, char* digit3)
{
    if (*digit2 >= 57) {
        *digit1 = *digit1 + 1;
        *digit2 = *digit1 + 1;
        *digit3 = *digit2 + 1;
    }
    my_putchar(*digit1);
    my_putchar(*digit2);
    my_putchar(*digit3);
    return (0);
}

int my_print_comb(void)
{
    char digit1 = 48;
    char digit2 = 49;
    char digit3 = 50;

    my_putchar(digit1);
    my_putchar(digit2);
    my_putchar(digit3);
    while (digit1 != '7') {
        my_putchar(',');
        my_putchar(' ');
        digit3++;
        if (digit3 > 57) {
            digit2++;
            digit3 = digit2 + 1;
        }
        fonct(&digit1, &digit2, &digit3);
    }
    return (0);
}
