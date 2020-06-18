/*
** EPITECH PROJECT, 2020
** my_option_get
** File description:
** return
*/

#include "../lib/my/my.h"

list_t *remove_elementfront(list_t *list)
{
    if (list != NULL)
    {
        list_t *send = list->following;
        free(list);
        return (send);
    }
    else return (NULL);
}

void livefre(list_t *list)
{
    while (list)
        list = remove_elementfront(list);
}

int my_strlen_list(list_t *list)
{
    int i = 0;

    while (list->following) {
        i += 1;
        list = list->following;
    }
    return (i);
}

char **list_to_tab(list_t *list, char **str)
{
    int i = 0;
    str = malloc(sizeof(char *) * (my_strlen_list(list) + 2));
    for (; list->following ; i++) {
        str[i] = malloc(sizeof(char) * my_strlen(list->env) + 10);
        str[i] = list->env;
        list = list->following;
    }
    str[i] = malloc(sizeof(char) * my_strlen(list->env) + 10);
    str[i] = list->env;
    str[++i] = NULL;
    return (str);
}

int my_add_end(list_t *list, char *eternel)
{
    list_t *element = my_create_egal("OLDPWD", eternel);
    list_t *m_list = list;
    while (m_list->following) m_list = m_list->following;
        m_list->following = element;
}