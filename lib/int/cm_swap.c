/*
** EPITECH PROJECT, 2023
** my_swap.c
** File description:
** swap two intergers
*/

#include "my_lib.h"

void cm_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
