/*
** EPITECH PROJECT, 2020
** my_getenv
** File description:
** return
*/

#include "../lib/my/my.h"

char *check_env(char **env, char *elem, int i, char *str)
{
    int index = 0;
    int j = 0;

    for (; env[i][index] != 61 ; index++);
    index += 1;
    for (; env[i][index] ; index++) {
        str[j] = env[i][index];
        j++;
    }
    str[j] = '\0';
    return (str);
}

char *my_getenv(char **env, char *elem)
{
    char *str = NULL;
    for (int i = 0 ; env[i] ; i++) {
        if (my_strcmp(env[i], elem) == 0) {
            str = malloc(sizeof(char) * (my_strlen(env[i]) + 2));
            check_env(env, elem, i, str);
            return (str);
        }
    }
    return (NULL);
}

int check_getline(char **str, list_t **list)
{
    if (my_strcmp_mn(str[0], "unsetenv") == 0) {
        for (int i = 1 ; str[i] ; i++)
            list = my_unsetenv(list, str[i]);
        if (str[1] == NULL) my_putstrtwo("unsetenv: Too few arguments\n");
        my_free_array(str);
        return (0);
    }
    if (my_strcmp_mn(str[0], "exit") == 0 && str[1] == NULL) {
        livefre(*list);
        my_free_array(str);
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strcmp_mn(str[0], "exit") == 0 && str[1] != NULL) {
        my_putstrtwo("exit: Expression Syntax.\n");
        my_free_array(str);
        return (0);
    }
    return (1);
}

int check_cd_env(char **str, list_t *list, char *get, eternel_t *eternel)
{
    if (my_strcmp_mn(str[0], "setenv") == 0) {
        my_setenv_end(list, str);
        my_free_array(str);
        return (0);
    }
    if (my_strcmp_mn(str[0], "env") == 0 && str[1] == NULL) {
        my_print_list(list);
        my_free_array(str);
        return (0);
    }
    if (my_strcmp_mn(str[0], "cd") == 0) {
        do_cd(list, str, get, eternel);
        my_free_array(str);
        return (0);
    }
    return (1);
}

int check_access(char *tab, char *str)
{
    if (access(my_strcat(tab, str), X_OK) == 0 || \
        ((my_strcmp_mn("/", str) == 0) && access(str , X_OK) == 0))
            return (0);
    return (1);
}