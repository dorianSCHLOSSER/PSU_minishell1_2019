/*
** EPITECH PROJECT, 2020
** my_cd
** File description:
** return
*/

#include "../lib/my/my.h"

void cd_without(list_t *list, char *get, eternel_t *eternel)
{
    char *old = getcwd(NULL, 0);
    eternel->old_pwd = my_strdup(old);
    my_old_pwd(list, old);
    chdir(get);
    my_pwd(list, get);
    free(old);
}

void chrch_old_pwd(list_t *list, char **pwd)
{
    while (list) {
        if (my_strcmp(list->env, "OLDPWD") == 0) {
            *pwd = check_pwd(list->env);
            chdir(*pwd);
            break;
        }
        list = list->following;
    }
}

void cd_tir(list_t *list, eternel_t *eternel)
{
    char *det = getcwd(NULL, 0);
    char *pwd = NULL;
    if (check_old_pwd(list) != 0)
        my_add_end(list, eternel->old_pwd);
    chrch_old_pwd(list, &pwd);
    my_pwd(list, pwd);
    free(pwd);
    my_old_pwd(list, det);
    eternel->old_pwd = my_strdup(det);
    free(det);
}

int my_cd(list_t *list, char *str, eternel_t *eternel)
{
    char *old = getcwd(NULL, 0);
    eternel->old_pwd = my_strdup(old);
    DIR *op  = opendir(str);
    if (chdir(str) == -1) {
        my_putstrtwo(str);
        my_putstrtwo(": ");
        my_putstrtwo(strerror(errno));
        my_putstrtwo(".\n");
        closedir(op);
        return (0);
    }
    my_old_pwd(list, old);
    my_pwd(list, getcwd(NULL, 0));
    closedir(op);
}

int do_cd(list_t *list, char **str, char *get, eternel_t *eternel)
{
    if (my_arrlen(str) > 2)
        my_putstrtwo("cd: Too many argument.\n");
    if (str[1] == NULL) {
        cd_without(list, get, eternel);
        return (0);
    }
    if (my_strcmp_mn(str[1], "-") == 0) {
        cd_tir(list, eternel);
        return (0);
    }
    my_cd(list, str[1], eternel);
    return (0);
}