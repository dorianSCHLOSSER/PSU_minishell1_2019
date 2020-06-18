/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** return
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s2[i] ; i++) {
        if (s1[i] != s2[i])
            return (1);
    }
    if (s1[i] == 61) return (0);
    return (1);
}