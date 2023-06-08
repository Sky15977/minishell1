/*
** EPITECH PROJECT, 2023
** unsetenv.c
** File description:
** BY - CM
*/

#include "shell.h"

void line_delete(shell_t *sh, char **tab, int y, int i)
{
    int a = 0;

    cm_freetab(sh->env);
    sh->env = malloc(sizeof(char *) * y);
    for (y = 0; tab[y] != NULL; y++) {
        if (y != i) {
            sh->env[a] = cm_strdup(tab[y]);
            a++;
        }
    }
    sh->env[a] = NULL;
}

void delete_line_env(shell_t *sh, char **tab)
{
    int i = 0;
    int x = 0;
    int y = 0;

    for (; tab[y]; y++) {
        for (x = 0; tab[y][x] != '=' && tab[y][x]; x++);
        if (cm_strncmp(sh->av[1], tab[y], x) == 0)
            i = y;
    }
    if (i != 0)
        line_delete(sh, tab, y, i);
}

void commant_unsetenv(shell_t *sh)
{
    int y = 0;
    char **tab = tab_in_tab(sh->env);

    for (; sh->av[y]; y++);
    if (y == 1) {
        cm_putstr(sh->av[0]);
        cm_putstr(": Too few arguments.\n");
        cm_freetab(tab);
        sh->ret = 1;
        return;
    }
    if (y > 1) {
        delete_line_env(sh, tab);
        cm_freetab(tab);
        return;
    }
}
