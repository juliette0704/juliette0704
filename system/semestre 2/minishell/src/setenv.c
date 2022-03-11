/*
** EPITECH PROJECT, 2021
** setenv.c
** File description:
** str
*/

#include "my.h"
#include <assert.h>

void print_env(char **env)
{
    int i = 0;
    while (env[i] != NULL){
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
}

void set_var_2_null (char **env, char *var_name)
{
    int last_env = 0;
    char **new_env = malloc(sizeof(env) + sizeof(var_name));
    new_env = env;   
    while (env[last_env] != NULL)
        last_env++;
    my_strcat(var_name, "=");
    new_env[last_env] = var_name;
    new_env[last_env + 1] = NULL;
    env = new_env;
}

void set_new_var_2_value (char **env, char *var_name, char *var_value)
{
    int last_env = 0;
    int last_of_name = 0;
    int i = 0;
    char *line_2_add = malloc(sizeof(var_name) + sizeof(var_value) + sizeof(char));
    line_2_add = var_name;
    while (line_2_add[last_of_name] != '\0') last_of_name ++;
    line_2_add[last_of_name] = '=';   
    while (var_value[i] != '\0') {
        line_2_add[last_of_name + i + 1] = var_value[i];
        i++;
   }
   line_2_add[last_of_name + i + 1]= '\0';
   char **new_env = malloc(sizeof env + sizeof(line_2_add));
   new_env = env;
   while (env[last_env] != NULL) last_env++;
   new_env[last_env] = line_2_add;
   new_env[last_env + 1] = NULL;
   env = new_env;
}

void set_var_2_value (char **env, char *var_name, char *var_value)
{
    int i = 0;
    int k = 0;
    while (env[i] != NULL && (compare(var_name, env[i]) != 1))
        i++;
    if (env[i] == NULL) {
        set_new_var_2_value(env, var_name, var_value);
        return ;
    }
    int last_of_name = 0;
    while (var_name[last_of_name] != '\0') last_of_name++;
    char* line_2_add = malloc(sizeof(var_name) + sizeof(var_value) + sizeof('='));
    line_2_add = var_name;
    line_2_add[last_of_name] = '=';
    while (var_value[k] != '\0') {
       line_2_add[last_of_name + k + 1] = var_value[k];
       k++;
    }
    line_2_add[last_of_name + k + 1] = '\0';
    env[i] = line_2_add;
}

int my_setenve(char **res, char **env)
{
    int i = 0;
        for (; res[i] != NULL; i++);
        if (i == 1) print_env(env);
        if (i == 2) set_var_2_null(env,res[1]);
        if (i == 3) set_var_2_value(env,res[1],res[2]);
        if (i > 3) my_putstr("setenv: Too many arguments.\n");
}