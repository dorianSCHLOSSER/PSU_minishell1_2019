/*
** EPITECH PROJECT, 2020
** my_check_pwd
** File description:
** return
*/

#include "../lib/my/my.h"

char *check_pwd(char *str)
{
    char *old = malloc(sizeof(char) * my_strlen(str));
    int index = 0;
    int j = 0;

    for (; str[index] != 61 ; index++);
    index += 1;
    for (; str[index] ; index++) {
        old[j] = str[index];
        j++;
    }
    old[j] = '\0';
    return (old);
}

int check_old_pwd(list_t *list)
{
    while (list) {
        if (my_strcmp(list->env, "OLDPWD") == 0) return (0);
        list = list->following;
    }
    return (1);
}

void my_pwd(list_t *list, char *str)
{
    while (list) {
        if (my_strcmp(list->env, "PWD") == 0) {
            list->env = my_strcat("PWD=", str);
        }
        list = list->following;
    }
}

void my_old_pwd(list_t *list, char *old)
{
    while (list) {
        if (my_strcmp(list->env, "OLDPWD") == 0) {
            list->env = my_strcat("OLDPWD=", old);
        }
        list = list->following;
    }
}