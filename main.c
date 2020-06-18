/*
** EPITECH PROJECT, 2020
** main
** File description:
** return
*/

#include "lib/my/my.h"

int main(int argc, char **argv, char **envp)
{
    if (argc != 1) return (84);
    char **str;
    eternel_t eternel;
    eternel.old_pwd = my_getenv(envp, "OLDPWD");
    char *get = my_getenv(envp, "HOME");
    list_t *list = my_params_list(envp);
    while (32) {
        my_getline(str, &list, get, &eternel);
    }
    return (0);
}