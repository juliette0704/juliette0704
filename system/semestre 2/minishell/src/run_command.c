/*
** EPITECH PROJECT, 2021
** run_command.c
** File description:
** cmd
*/

#include "my.h"
#include "navy.h"

int run_commande(char *path, char **res, char **env)
{
    if (fork() != 0)
        wait(NULL);
    else {
        if (execve(path, res, env) == -1)
                write(2, "segfault\n", 9);
            else
                execve(path, res, env);
            exit(0);
    }
}


void run_command(char **res, char **env)
{
    int i = 0;
    char dest[5] = "PATH";
    char test2[200] = "/";
    while (compare(dest, env[i]) != 1) i++;
    char **pathenv = str_to_word_array4(env[i]);
    pathenv = str_to_word_array2(pathenv[1]);
    char test[200] = "/";
    int h = 0;
    int nb = 0;
    if (no_slash(res) == 1) {
        if (access(res[0], F_OK) == 0)
            run_commande(res[0], res, env);
        else {
            my_putstr(res[0]);
            my_putstr(": Command not found.\n");
        }
    } else {
        my_strcat(test2, res[0]);
        while (pathenv[h] != NULL) {
            char *path2 = pathenv[h];
            my_strcat(path2, test2);
            if (access(path2, F_OK) == 0) {
                run_commande(pathenv[h], res, env);
                break;
            }
            h++;
        }
    }
}