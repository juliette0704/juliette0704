/*
** EPITECH PROJECT, 2021
** cat.c
** File description:
** task
*/

#include <fcntl.h> 
#include <stdio.h> 
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    int i;
    i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}

int main(int argc, char *argv[32000])
{
    int n = 0;
    char max[32000];
    int fd = 0;
    if(argc == 1) {
         while (1){
             read(0, max, 32000);
             my_putstr(max);
             for(int j = 0; j < 32000; j++)
                 max[j] = 0;
         }
    }
    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            write(2, "ERROR", 5);
            return 84;
        }
        n = read(fd, max, 32000);
        my_putstr(max);
        for(int j = 0; j < 32000; j++)
            max[j] = 0;
        close (fd);
    }
    my_putchar('\n');
    return 0;
}
