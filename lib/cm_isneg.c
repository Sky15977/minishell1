/*
** EPITECH PROJECT, 2023
** cm_isneg.c
** File description:
** BY - CM
*/

#include "my_lib.h"

int cm_isneg(int nb)
{
    if (nb >= 0)
        cm_putchar('P');
    else
        cm_putchar('N');
    return SUCESS;
}
