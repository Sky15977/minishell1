/*
** EPITECH PROJECT, 2022
** cm_puttab.c
** File description:
** BY - CM
*/

#include "my_lib.h"

void cm_puttab(char **tab)
{
    for (int y = 0; tab[y] != NULL; y++) {
        cm_putstr(tab[y]);
        write(1, "\n", 1);
    }
}

void cm_puttab_error(char **tab)
{
    for (int y = 0; tab[y] != NULL; y++) {
        cm_putstr_error(tab[y]);
        write(2, "\n", 1);
    }
}
