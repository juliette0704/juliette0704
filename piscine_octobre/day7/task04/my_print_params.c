/*
** EPITECH PROJECT, 2021
** my_print_params.c
** File description:
** task
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *argv)
{
    int i = 0;
    while (argv[i] != '\0') {
        i++;
        my_putchar[argv][i]
    }
    return (i);
}

int main(int argc, char **argv)
{
	int i = 0;
	while(i < argc) {
	my_putstr(argv[i]);
	my_putchar('\n');
	i++;
    }
    return (0);
}
