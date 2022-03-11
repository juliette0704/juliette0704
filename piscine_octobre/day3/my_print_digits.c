/*
** EPITECH PROJECT, 2021
** my_print_digits.c
** File description:
** task
*/

int my_print_digits(void)
{
    char digits;

    digits = 48;
    while (digits <= 57) {
        my_putchar(digits);
        digits++;
    }
    return (0);
}
