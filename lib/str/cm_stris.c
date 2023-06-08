/*
** EPITECH PROJECT, 2023
** my_str_is.c
** File description:
** is_alphanum
*/

#include "my_lib.h"

int cm_str_isalpha(char const *str)
{
    for (UINT i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return TRUE;
    return FALSE;
}

int cm_str_islower(char const *str)
{
    for (UINT i = 0; str[i] != '\0'; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return TRUE;
    return FALSE;
}

int cm_str_isnum(char const *str)
{
    for (UINT i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9')
            return TRUE;
    return FALSE;
}

int cm_str_isprintable(char const *str)
{
    for (UINT i = 0; i != '\0'; i++)
        if (str[i] < 32 || str[i] > 126)
            return TRUE;
    return FALSE;
}

int cm_str_isupper(char const *str)
{
    for (UINT i = 0; str[i] != '\0'; i++)
        if (str[i] < 'A' || str[i] > 'Z')
            return TRUE;
    return FALSE;
}
