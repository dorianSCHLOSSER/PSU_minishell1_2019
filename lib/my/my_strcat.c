/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** return
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char *src)
{
    if (dest == NULL) return (src);
    int dest_len = my_strlen(dest) + my_strlen(src);
    char *str = malloc(sizeof(char) * dest_len + 2);
    int i = 0;

    for (i = 0 ; dest[i] ; i++)
        str[i] = dest[i];
    for (int j = 0 ; src[j] ; j++)
        str[i++] = src[j];
    str[i] = '\0';

    return (str);
}