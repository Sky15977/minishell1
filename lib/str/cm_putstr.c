/*
** EPITECH PROJECT, 2023
** cm_putstr.c
** File description:
** BY - CM
*/

#include "my_lib.h"

void cm_putstr(char const *str)
{
    write(1, str, cm_strlen(str));
}

void cm_putstr_error(char const *str)
{
    write(2, str, cm_strlen(str));
}
