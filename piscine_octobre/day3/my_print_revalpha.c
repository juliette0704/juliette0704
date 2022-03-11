/*
** EPITECH PROJECT, 2021
** my_print_revalpha.c
** File description:
** task
*/

int my_print_revalpha(void)
{
    char alphabet;

    alphabet = 122;
    while (alphabet >= 97) {
        my_putchar(alphabet);
        alphabet--;
    }
    return (0);
}
