/*
** EPITECH PROJECT, 2020
** my_error
** File description:
** return
*/

#include "../lib/my/my.h"

void my_error_global(char **str)
{
    my_putstrtwo(str[0]);
    my_putstrtwo(": Command not found.\n");
}

int my_is_alpha(char c)
{
    if (c >= 'a' && c <= 'z') return (0);
    if (c >= 'A' && c <= 'Z') return (0);
    if (c == '_') return (0);
    return (1);
}

int my_is_num(char c)
{
    if (c >= '0' && c <= '9') return (0);
    return (1);
}

int my_error_setenv(char *str)
{
    for (int i = 1 ; str[i] ; i++) {
        if (my_is_alpha(str[0]) == 1) {
            my_putstrtwo("setenv: Variable name must begin with a letter.\n");
            return (0);
        }
        if (my_is_num(str[i]) == 1 && my_is_alpha(str[i]) == 1) {
            my_putstrtwo("setenv: Variable name must contain ");
            my_putstrtwo("alphanumeric characters.\n");
            return (0);
        }
    }
    return (1);
}

int my_error_set(char **str, list_t *list)
{
    int i = 0;
    for (; str[i] ; i++);
    if (i < 2) {
        my_print_list(list);
        return (0);
    }
    if (i >= 4) {
        my_putstrtwo("setenv: Too many arguments.\n");
        return (0);
    }
    return (1);
}