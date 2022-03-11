/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "my.h"

int is_it_env(char **env)
{
    int i = 0;
    while (env[i] != NULL) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
}

char **read_command(char **res, char **env)
{
    char *pos = malloc(sizeof(char*));
    size_t size = 10;
    if (getline(&pos, &size, stdin) == -1) {
        my_putstr("exit\n");
        exit(0);
    }
    strtok(pos, "\n");
    if (pos[0] == ' ') {
        char *pos2 = delete_space(pos);
        res = str_to_word_array(pos2);
    } else
        res = str_to_word_array(pos);
    return res;
}

void the_loop(char **env)
{
    char **res;
    char setenv[8] = "setenv";
    char unset[10] = "unsetenv";
    char path[100] = "/bin/";
    char enve[5] = "env";
    int i = 0, j = 0;
    while (1) {
        my_putstr("$> ");
        res = read_command(res,env);
        if (res[0][0] == 'c' && res[0][1] == 'd') {
            run_cd(res, env);
            goto end;
        }
        if (res[0][0] == '\0')
            goto end;
        if (res[0][0] == 'e' && res[0][1] == 'x' && res[0][2] == 'i' && res[0][3] == 't') {
            my_putstr("exit\n");
            break;
        }
        if (compare(unset, res[0]) == 1) {
            unsete(res, env);
            goto end;
        }
        if (compare(enve, res[0]) == 1) {
            print_env(env);
            goto end;
        }
        if (compare(setenv, res[0]) == 1) {
            my_setenve(res, env);
            goto end;
        }
        if (res[0][0] != 10)
            run_command(res, env);
        end :
    }
}

int main(int argc ,char *argv[] ,char **env)
{
    int nb = 0;
    the_loop(env);
}
