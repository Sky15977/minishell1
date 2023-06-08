/*
** EPITECH PROJECT, 2023
** my_strcpy.c
** File description:
** Copy a string into another
*/

#include "my_lib.h"

char *cm_strcpy(char *dest, char const *src)
{
    for (UINT i = 0; i == 0 || src[i - 1] != '\0'; i++)
        dest[i] = src[i];
    return dest;
}

char *cm_strncpy(char *dest, char const *src, UINT n)
{
    for (UINT i = 0; i < n - 1; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return dest;
}
