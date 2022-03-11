/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** square
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

#ifndef MY_H_
    #define MY_H_

char **str_to_word_array(char *chaine);
char **str_to_word_array2(char *chaine);
char **str_to_word_array3(char *chaine);
char **str_to_word_array4(char *chaine);
int my_strlen(char *str);
char *my_strstr(char *str, char *to_find);
int run_cd(char **res, char **env);
int compare(char *s1, char *s2);
char *my_strcat(char *dest, char *src);
void run_command(char **res, char **env);
int run_commande(char *path, char **res, char **env);
void my_putstr(char *str);
void my_putchar(char c);
char *my_strcat(char *dest, char *src);
int compare(char *s1, char *s2);
int my_setenve(char ** ,char **);
int unsete(char **res, char **env);
void print_env(char **env);
char *delete_space(char *res);
int no_slash(char **res);

#endif /* !MY_H_ */