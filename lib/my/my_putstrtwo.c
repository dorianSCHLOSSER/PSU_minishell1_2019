/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** return
*/

#include <unistd.h>

int my_putstrtwo(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    write(2, str, i);

    return (0);
}