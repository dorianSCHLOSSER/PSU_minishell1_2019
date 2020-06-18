/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** return
*/

int my_strlen(char const *str)
{

    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_arrlen(char **str)
{
    int i = 0;

    for (; str[i] ; i++);
    return (i);
}
