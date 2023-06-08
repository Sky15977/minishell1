/*
** EPITECH PROJECT, 2023
** cm_prompt
** File description:
** BY - CM
*/

#include "shell.h"

void cm_prompt(shell_t *sh)
{
    if (sh->ret != 0)
        cm_putstr("\033[1;31m[cmatthew - ");
    else
        cm_putstr("\033[1;34m[cmatthew - ");
    cm_putnbr(sh->ret);
    cm_putstr("]$ \033[0m");
}
