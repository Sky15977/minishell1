/*
** EPITECH PROJECT, 2023
** cd.c
** File description:
** BY - CM
*/

#include "shell.h"

void cd_previous(shell_t *sh)
{
    char *str = NULL;
    char *tab[4] = {"setenv", "PWD", NULL, NULL};

    if (sh->pwd_previous == NULL) {
        cm_putstr(": No such file or directory.\n");
        sh->ret = 1;
    } else {
        str = get_pwd(sh);
        chdir(sh->pwd_previous);
        change_pwd(sh, tab, sh->pwd_previous);
        sh->pwd_previous = cm_strdup(str);
        free(str);
    }
}

void cd_back(shell_t *sh)
{
    char *filepath = NULL;
    char *tab[4] = {"setenv", "PWD", NULL, NULL};

    check_pwd_previous(sh);
    filepath = get_pathback(sh);
    chdir("../");
    change_pwd(sh, tab, filepath);
}

void cd_after(shell_t *sh)
{
    char *filepath = NULL;
    char *tab[4] = {"setenv", "PWD", NULL, NULL};

    check_pwd_previous(sh);
    filepath = concat_filepath(sh->pwd_previous, sh->av[1]);
    if (access(filepath, F_OK) != 0) {
        cm_putstr(sh->av[1]);
        cm_putstr(": No such file or directory.\n");
        sh->ret = 1;
        return;
    }
    if (check_directory(sh) != 0)
        return;
    chdir(filepath);
    change_pwd(sh, tab, filepath);
}

int first_command_cd(shell_t *sh, unsigned int y)
{
    if (y == 1) {
        cd_basics(sh);
        return 0;
    }
    if (sh->av[1][0] == '/') {
        cd_with_path(sh);
        return 0;
    }
    return 1;
}

void command_cd(shell_t *sh)
{
    unsigned int y = 0;

    for (; sh->av[y]; y++);
    if (y > 2) {
        cm_putstr(sh->av[0]);
        cm_putstr(": Too many arguments.\n");
        sh->ret = 1;
        return;
    } else if (first_command_cd(sh, y) == 0)
        return;
    if (cm_strcmp(sh->av[1], "-") == 0) {
        cd_previous(sh);
        return;
    }
    if (cm_strcmp(sh->av[1], "../") == 0 || cm_strcmp(sh->av[1], "..") == 0) {
        cd_back(sh);
        return;
    }
    cd_after(sh);
    return;
}
