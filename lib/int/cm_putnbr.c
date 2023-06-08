/*
** EPITECH PROJECT, 2022
** cm_putnbr.c
** File description:
** BY - CM
*/

#include "my_lib.h"

unsigned int cm_putnbr(int nb)
{
    UINT count = 0;

    if (nb < 0) {
        nb = nb * -1;
        cm_putchar('-');
        count++;
    }
    if (nb >= 0 && nb < 10) {
        cm_putchar(nb + 48);
        count++;
        return count;
    }
    count++;
    count += cm_putnbr(nb / 10);
    cm_putchar ((nb % 10) + 48);
    return count;
}

unsigned int cm_putnbr_base(int nbr, char const *base)
{
    UINT count = 0;
    UINT nb_base = cm_strlen(base);

    if (nbr < 0) {
        nbr = nbr * -1;
        cm_putchar('-');
        count++;
    }
    if (nbr >= 0 && nbr < (int)nb_base) {
        cm_putchar(base[nbr]);
        count++;
        return count;
    }
    count++;
    count += cm_putnbr_base((nbr / nb_base), base);
    cm_putchar(base[nbr % nb_base]);
    return count;
}
