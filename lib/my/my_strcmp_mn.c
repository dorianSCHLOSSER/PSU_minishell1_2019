/*
** EPITECH PROJECT, 2019
** my_strcmp_mn
** File description:
** return
*/

int my_strcmp_mn(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] ; i++) {
        if (s1[i] != s2[i])
            return (1);
    }
    if (s2[i] != '\0') return (1);
    return (0);
}
