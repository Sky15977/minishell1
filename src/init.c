/*
** EPITECH PROJECT, 2023
** init.c
** File description:
** BY - CM
*/

#include "shell.h"

char **tab_in_tab(char **tab)
{
    int i = 0;
    int y = 0;
    char **bis = NULL;

    for (; tab[i]; i++);
    bis = malloc(sizeof(char *) * (i + 1));
    for (; tab[y]; y++) {
        bis[y] = cm_strdup(tab[y]);
    }
    bis[y] = NULL;
    return bis;
}

void init_shell(shell_t *sh)
{
    sh->ret = 0;
    sh->pwd = NULL;
    sh->pwd_previous = NULL;
    sh->lineptr = NULL;
    sh->av = NULL;
    sh->env = NULL;
}
