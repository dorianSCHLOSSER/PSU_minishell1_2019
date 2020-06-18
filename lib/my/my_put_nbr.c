/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** return
*/

#include <limits.h>

void my_putchar(char c);

int my_putstr(char const *str);

void my_put_nbr(int nb)
{
    if (nb == INT_MIN) my_putstr("-2147483648");
    if (nb < 0 && nb > INT_MIN + 1) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    else {
        if (nb != INT_MIN) my_putchar(48 + nb);
    }
}
