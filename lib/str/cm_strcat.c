/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** m
*/

#include "my_lib.h"

char *cm_strcat(char *dest, char const *src)
{
    UINT i = 0;
    UINT a = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[a] != '\0'; a++) {
        dest[i] = src[a];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *cm_strncat(char *dest, char const *src, UINT n)
{
    UINT length = cm_strlen(dest);
    UINT i = 0;

    for (; src[i] != 0 && i < n - 1; i++)
        dest[i + length] = src[i];
    dest[i] = '\0';
    return dest;
}
