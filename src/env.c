/*
** EPITECH PROJECT, 2023
** env.c
** File description:
** BY - CM
*/

#include "shell.h"

void command_env(shell_t *sh)
{
    int y = 0;

    for (; sh->av[y]; y++);
    if (y == 1)
        cm_puttab(sh->env);
    else {
        cm_putstr(sh->av[0]);
        cm_putstr(": '");
        cm_putstr(sh->av[1]);
        cm_putstr(": No such file or directory\n");
    }
}
