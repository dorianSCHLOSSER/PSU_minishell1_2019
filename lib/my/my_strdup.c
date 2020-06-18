/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** return
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int i = 0;
    char *memory = malloc(sizeof(char) * (my_strlen(src) + 1));

    for (; src[i] != '\0' ; i++)
        memory[i] = src[i];
    memory[i] = '\0';

    return (memory);
}
