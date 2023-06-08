/*
** EPITECH PROJECT, 2023
** free.c
** File description:
** free my alloc
*/

#include "my_lib.h"

void cm_freetab(char **tab)
{
    for (UINT i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
