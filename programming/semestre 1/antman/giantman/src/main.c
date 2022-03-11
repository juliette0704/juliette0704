/*
** EPITECH PROJECT, 2021
** main
** File description:
** antman
*/

#include "my.h"

// void picture(char *str)
// {
//     char temp[100];
//     int k = 0;
//     int j;
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (str[i] < '0' || str[i] > '9') {
//             my_putchar(str[i]);
//         } else {
//             for (j = i; str[j] >= '0' && str[j] <= '9'; j++) {
//                 temp[k] = str[j];
//                 k++;
//             }
//             i = j - 1;
//             k = 0;
//             my_putcstr(temp);
//             // printf("temp : %s\n", temp);
//         }
//     }
//     return;
// }

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
    
    for (int i = 0; map[i] != '\0'; i++) {
        my_put_nbr(map[i]);
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
