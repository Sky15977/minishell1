/*
** EPITECH PROJECT, 2023
** cd_bis.c
** File description:
** BY - CM
*/

#include "shell.h"

void change_pwd(shell_t *sh, char **tab, char *filepath)
{
    cm_freetab(sh->av);
    tab[2] = cm_strdup(filepath);
    sh->av = tab_in_tab(tab);
    free(tab[2]);
    command_setenv(sh);
    free(filepath);
}

void cd_with_path(shell_t *sh)
{
    char *filepath = NULL;
    char *tab[4] = {"setenv", "PWD", NULL, NULL};
    DIR *dir = opendir(sh->av[1]);

    if (dir != NULL) {
        check_pwd_previous(sh);
        filepath = cm_strdup(sh->av[1]);
        chdir(filepath);
        change_pwd(sh, tab, filepath);
    } else {
        cm_putstr(sh->av[1]);
        cm_putstr(": Not a directory.\n");
        sh->ret = 1;
    }
}

void cd_basics(shell_t *sh)
{
    char *filepath = NULL;
    char *tab[4] = {"setenv", "PWD", NULL, NULL};

    check_pwd_previous(sh);
    filepath = cm_strdup("/home/epitech");
    chdir(filepath);
    change_pwd(sh, tab, filepath);
}
