/*
** EPITECH PROJECT, 2020
** my_builtt
** File description:
** return
*/

#include "../lib/my/my.h"

list_t **my_unsetenv(list_t **list, char *str)
{
    list_t *live = *list;
    list_t *tmp;

    if (my_strcmp(live->env, str) == 0) {
        *list = live->following;
        free(live);
        return (list);
    }
    tmp = live->following;
    while (tmp) {
        if (my_strcmp(tmp->env, str) == 0) {
            live->following = tmp->following;
            free(tmp);
            return (list);
        }
        live = tmp;
        tmp = tmp->following;
    }
    return (list);
}