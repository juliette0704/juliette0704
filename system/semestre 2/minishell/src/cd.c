/*
** EPITECH PROJECT, 2021
** cd.c
** File description:
** main
*/

#include "my.h"

int no_slash(char **res)
{
    int j = 0;
    for (int i = 0; res[i] != NULL; i++) {
        while (res[i][j] != '\0') {
                if (res[i][j] == '/')
                return 1;
            j++;
        }
    }
    return 0;
}

void find_cwd(char **env, char **res, char cwd[])
{
    int i = 0;
    char dest[5] = "PWD=";
    char slash[40] = "/";
    char **result;
    char tempo[1000];
    char fin[555] = "PWD=";
    while (compare(dest, env[i]) != 1)
        i++;
    if (res[1][0] == '.' && res[1][1] == '.' && my_strlen(res[1]) == 2) {
        getcwd(tempo, 1000);
        my_strcat(fin, tempo);
        env[i] = fin;
    } else {
        my_strcat(slash, res[1]);
        my_strcat(cwd, slash);
        my_strcat(fin, cwd);
        env[i] = fin;
    }
}

void find_logname(char **env)
{
    int i = 0;
    char name[8] = "LOGNAME";
    char home[200] = "/home/";
    while (compare(name, env[i]) != 1)
        i++;
    char **pathenv = str_to_word_array(env[i]);
    my_strcat(home, pathenv[1]);
    chdir(home);
}

void just_cd(char **env, char **res)
{
    char cwd[200];
    int i = 0;
    int j = 0;
    char home[6] = "HOME";
    char fin[100] = "PWD=";
    while (compare(home, env[i]) != 1)
        i++;
    char **cede = str_to_word_array4(env[i]);
    chdir(cede[1]);
    while (compare(fin, env[j]) != 1)
        j++;
    my_strcat(fin, cede[1]);
    env[j] = fin;
}

int run_cd(char **res, char **env)
{
    char cwd[300];
    char oldenv[300] = "OLDPWD=";
    char lastpwd[300];
    int i = 0;
    int yes = 0;
    getcwd(lastpwd, 300);
    for (int k = 0; env[k] != NULL; k++) {
        if (env[k][3] == 'P' && env[k][0] == 'O') {
            while (compare(oldenv, env[i]) != 1)
                i++;
            yes = 1;
        }
    }
    char old[300] = "OLDPWD ";
    char place[300];
    getcwd(place, 300);
    char fin[300] = "./a.out ";
    my_strcat(old, place);
    my_strcat(fin, old);
    char **oldenve = str_to_word_array(fin); // old
    if (yes == 0) {
        my_setenve(oldenve, env);
    } else {
        my_strcat(oldenv, lastpwd);
        env[i] = oldenv;
    }
    if (res[1] != NULL) {
        getcwd(cwd, 300);
        if (res[1][0] == '~')
            just_cd(env, res);
        else {
            if (access(res[1], F_OK) == 0) {
                chdir(res[1]);
                if (no_slash(res) == 0)
                    find_cwd(env, res, cwd);
                return 1;
            } else if (access(res[1], F_OK) == -1)
                my_putstr(res[1]);
                my_putstr(": No such file or directory.\n");
        }
    } else
        just_cd(env, res);
    return 0;
}