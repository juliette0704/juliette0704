/*
** EPITECH PROJECT, 2021
** main
** File description:
** antman
*/

#include "my.h"
#include "antman.h"

void picture(char *str)
{
    //my_putstr(str);
    char *temp;
    int k = 0;
    int j;
    int x = 0;
    int i = 0;
    int j = 0;

    while (i < 15) {
        if (str[j] == '\n') {
            i++;
            j++;
        } else
            j++;
    }
    for (int i = 0; str[i] != '\0';) {
        if (str[i] == '\n' || str[i] == ' ') {
            if (str[i] == '\n')
                my_putchar('n');
            if (str[i] == ' ')
                my_putchar(' ');
        } else {
            for (j = i; str[j] != '\n'; j++);
            temp = malloc(sizeof(char) * j - i + 1);
            for (x = i; str[x] != '\n'; x++) {
                temp[k] = str[x];
                k++;
            }
            int test = j - i;
            temp[j - i] = '\0';
            i = j + 1;
            k = 0;
            my_putcstr(temp);
        }
    }
    return;
}

int is_only_digits(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}

int open_read(char **av)
{
    struct stat buf;
    stat(av[1], &buf);
    int size = buf.st_size;
    int fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        write(2, "EMPTY_FILE\n", 11);
        return 84;
    }
    char *map = malloc(size + 1);
    int nb = read(fd, map, size);
    map[size] = '\0';
    close(fd);
    if (av[2][0] == '3') {
		picture(map);
		return 0;
	}
    if (!is_only_digits(map) || av[2][1] == '1') {
        my_putcstr(map);
    }
    return 0;
}

int main(int ac , char **av)
{
    if (ac != 3) {
        write(2, "CHECK AV\n", 9);
        return 84;
    }
    open_read(av);
    return 0;
}
