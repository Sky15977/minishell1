/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** compare 2 str
*/

#include "my_lib.h"

int cm_strcmp(char const *s1, char const *s2)
{
    UINT i = 0;

    for (; (s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'); i++);
    return (s1[i] - s2[i]);
}

int cm_strncmp(char const *s1, char const *s2, UINT n)
{
    UINT i = 0;

    if (n < 1)
        return SUCESS;
    for (; i < n; i++) {
        if (s1[i] != s2[i])
            return s1[i] - s2[i];
        if (s1[i] == '\0' && s2[i] == '\0')
            return SUCESS;
    }
    return SUCESS;
}
