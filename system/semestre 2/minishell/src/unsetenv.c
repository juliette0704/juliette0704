/*
** EPITECH PROJECT, 2021
** unset.c
** File description:
** main
*/

#include "my.h"
#include <assert.h>

int unsetValue(char** env, char* var_name)
{
    int i = 0; 
    int j = 0; 
    int k = 0;
    while (env[i] != NULL && (compare(var_name, env[i]) != 1))
        i++;
    if (env[i] == NULL) {    
        my_putstr("This variable does not exist\n");
        return -1;
        }
    char** tmp_env = malloc(sizeof(env));
    tmp_env = env;
    while (env[k] != NULL) {
        tmp_env[j] = env[k];
        if (k != i){
            j++;
            k++;
        }
        else
            k++;
     }
    tmp_env[j] = NULL;
    env = tmp_env;
    return 0;
}

int unsete(char **res ,char **env)
{
    int i = 0;
    for (; res[i] != NULL; i++);
    if (i == 2) unsetValue(env, res[1]);
    else my_putstr("unsetenv: Too few arguments.\n");
}