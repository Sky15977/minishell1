/*
** EPITECH PROJECT, 2023
** my_strupcase.c
** File description:
** low in up
*/

#include "my_lib.h"

char *cm_strupcase(char *str)
{
    for (UINT i = 0; str[i] != '\0'; i++)
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    return str;
}
