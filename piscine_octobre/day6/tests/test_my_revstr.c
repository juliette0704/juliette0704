/*
** EPITECH PROJECT, 2021
** test_my_revstr.c
** File description:
** task
*/
    
# include <criterion/criterion.h>

char *my_revstr(char *str);

Test (my_revstr,reverse_str)
{
    char str[] = "HelloWorld";

    cr_assert_str_eq(my_revstr(str), "dlroWolleH");
}
