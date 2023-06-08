/*
** EPITECH PROJECT, 2023
** cm_putchar.c
** File description:
** BY - CM
*/

#include "my_lib.h"

void cm_putchar(char c)
{
    write(1, &c, 1);
}

void cm_putchar_error(char c)
{
    write(2, &c, 1);
}
