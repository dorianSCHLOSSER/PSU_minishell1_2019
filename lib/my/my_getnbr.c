/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** return
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int daisy = 1;

    if (str[0] == '-' && str[1] >= '0' && str[1] <= '9') {
        daisy = daisy * (-daisy);
        i++;
    }
    while (str[i] != '\0') {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '\n') return (-666);
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
            i++;
        }
        else return (nbr * daisy);
    }
    return (nbr * daisy);
}
