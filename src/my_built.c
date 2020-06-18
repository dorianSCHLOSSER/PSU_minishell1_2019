/*
** EPITECH PROJECT, 2020
** my_built
** File description:
** return
*/

#include "../lib/my/my.h"

list_t *my_create_node(char *envp)
{
    list_t *node = NULL;

    node = malloc(sizeof(*node));
    if (node == NULL) return (NULL);
    node->env = envp;
    node->following = NULL;

    return (node);
}

list_t *my_create_egal(char *envp, char *str)
{
    list_t *node = NULL;

    node = malloc(sizeof(*node));
    if (node == NULL) return (NULL);
    if (str == NULL)
        node->env = my_strcat(envp, "=");
    else
        node->env = my_strcat(my_strcat(envp, "="), str);

    node->following = NULL;

    return (node);
}

list_t *my_params_list(char **envp)
{
    list_t *node = my_create_node(envp[0]);
    list_t *list = node;

    for (int i = 1; envp[i] ; i++) {
        node->following = my_create_node(envp[i]);
        node = node->following;
    }

    return (list);
}

void my_print_list(list_t *list)
{
    while (list) {
        my_putstr(list->env);
        my_putchar('\n');
        list = list->following;
    }
}

int my_setenv_end(list_t *list, char **str)
{
    if (my_error_set(str, list) == 0) return (0);
    if (my_error_setenv(str[1]) == 0) return (0);
    list_t *element = my_create_egal(str[1], str[2]);
    list_t *mlist = list;

    while (mlist->following) {
        if (my_strcmp(mlist->env, str[1]) == 0) {
            mlist->env = element->env;
            return (0);
        }
        mlist = mlist->following;
    }
    if (my_strcmp(mlist->env, str[1]) == 0) {
        mlist->env = element->env;
        return (0);
    }
    mlist->following = element;
}