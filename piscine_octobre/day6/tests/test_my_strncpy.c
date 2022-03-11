/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** task
*/

# include <criterion/criterion.h>

char *my_strncpy(char *dest, char const *src, int n);

Test (my_strncpy ,copy_five_characters_in_empty_array )
{
    char dest[6] = {0};
    
    my_strncpy(dest, "HelloWorld", 5);
    cr_assert_str_eq(dest, "Hello");
}
