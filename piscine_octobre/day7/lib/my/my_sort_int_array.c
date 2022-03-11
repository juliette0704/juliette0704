/*
** EPITECH PROJECT, 2021
** my_sort_in_array.c
** File description:
** task
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int y = 0;
    for(int j = 0; j <= size ;j++) {
        i = 0;
        for(int i = 0; i <= size ;i++) {
            if (array[i] > array[i + 1])
                my_swap(&array[i], &array[i + 1]);
        }
    }
}
