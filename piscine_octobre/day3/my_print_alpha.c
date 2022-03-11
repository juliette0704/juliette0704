/*
** EPITECH PROJECT, 2021
** my_print_alpha.c
** File description:
** task
*/

int my_print_alpha(void)
{
    char alphabet;

    alphabet = 97;
    while (alphabet <= 122) {
        my_putchar(alphabet);
        alphabet++;
    }
}
