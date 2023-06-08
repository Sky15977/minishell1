/*
** EPITECH PROJECT, 2023
** setenv.c
** File description:
** BY - CM
*/

#include "shell.h"

void concat_new_line(shell_t *sh, char *str, int y)
{
    sh->env[y][0] = '\0';
    sh->env[y] = cm_strcat(sh->env[y], sh->av[1]);
    sh->env[y] = cm_strcat(sh->env[y], "=");
    sh->env[y] = cm_strcat(sh->env[y], str);
    sh->env[y + 1] = NULL;
    free(str);
}

void line_new(shell_t *sh, char **tab, int y)
{
    int nb = 0;
    char *str = NULL;

    if (sh->av[2] != NULL) {
        nb = cm_strlen(sh->av[1]) + cm_strlen(sh->av[2]) + 2;
        str = cm_strdup(sh->av[2]);
    } else {
        nb = cm_strlen(sh->av[1]) + 2;
        str = cm_strdup("\0");
    }
    cm_freetab(sh->env);
    sh->env = malloc(sizeof(char *) * (y + 2));
    for (y = 0; tab[y] != NULL; y++) {
        sh->env[y] = cm_strdup(tab[y]);
    }
    sh->env[y] = malloc(sizeof(char) * nb);
    concat_new_line(sh, str, y);
}

void line_exist(shell_t *sh, int i)
{
    int nb = 0;
    char *str = NULL;

    if (sh->av[2] != NULL) {
        nb = cm_strlen(sh->av[1]) + cm_strlen(sh->av[2]) + 2;
        str = cm_strdup(sh->av[2]);
    } else {
        nb = cm_strlen(sh->av[1]) + 2;
        str = cm_strdup("\0");
    }
    free(sh->env[i]);
    sh->env[i] = malloc(sizeof(char) * nb);
    sh->env[i][0] = '\0';
    sh->env[i] = cm_strcat(sh->env[i], sh->av[1]);
    sh->env[i] = cm_strcat(sh->env[i], "=");
    sh->env[i] = cm_strcat(sh->env[i], str);
    free(str);
}

void add_line_env(shell_t *sh, char **tab)
{
    int i = 0;
    int y = 0;
    int x = 0;

    if (error_setenv(sh, sh->av[1]) != 0)
        return;
    for (; tab[y]; y++) {
        for (x = 0; tab[y][x] != '=' && tab[y][x]; x++);
        if (cm_strncmp(sh->av[1], tab[y], x) == 0)
            i = y;
    }
    if (i != 0)
        line_exist(sh, i);
    else
        line_new(sh, tab, y);
}

void command_setenv(shell_t *sh)
{
    int y = 0;
    char **tab = tab_in_tab(sh->env);

    for (; sh->av[y]; y++);
    if (y == 1)
        cm_puttab(sh->env);
    if (y > 1 && y < 4) {
        add_line_env(sh, tab);
        cm_freetab(tab);
        return;
    }
    if (y > 3) {
        cm_putstr(sh->av[0]);
        cm_putstr(": Too many arguments.\n");
        cm_freetab(tab);
        sh->ret = 1;
        return;
    }
}
