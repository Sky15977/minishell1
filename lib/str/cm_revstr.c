/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** Write a function that reverses a string.
*/

#include "my_lib.h"

char *cm_revstr(char *str)
{
    UINT i = 0;
    char c = str[0];
    UINT nb = cm_strlen(str) - 1;

    for (; i <= nb / 2 + 1; i++) {
        c = str[i];
        str[i] = str[nb];
        str[nb] = c;
        nb--;
    }
    return str;
}
