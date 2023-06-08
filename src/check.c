/*
** EPITECH PROJECT, 2023
** check.c
** File description:
** BY - CM
*/

#include "shell.h"

int error_setenv(shell_t *sh, char const *str)
{
    if (str[0] < 65 || (str[0] > 90 && str[0] < 95) || str[0] > 122) {
        cm_putstr(sh->av[0]);
        cm_putstr(": Variable name must begin with a letter.\n");
        sh->ret = 1;
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++)
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z')
            && (str[i] < '0' || str[i] > '9') && str[i] != 95) {
            cm_putstr(sh->av[0]);
            cm_putstr(": Variable name must contain alphanumeric");
            cm_putstr(" characters.\n");
            sh->ret = 1;
            return 1;
        }
    return 0;
}

int check_directory(shell_t *sh)
{
    DIR *dir;

    dir = opendir(sh->av[1]);
    if (dir == NULL) {
        cm_putstr(sh->av[1]);
        cm_putstr(": Not a directory.\n");
        sh->ret = 1;
        return 1;
    }
    closedir(dir);
    return 0;
}

void check_pwd_previous(shell_t *sh)
{
    if (sh->pwd_previous == NULL)
        sh->pwd_previous = get_pwd(sh);
    else {
        free(sh->pwd_previous);
        sh->pwd_previous = get_pwd(sh);
    }
}

void check_access(shell_t *sh)
{
    DIR *dir;

    dir = opendir(&sh->av[0][2]);
    if (access(&sh->av[0][2], X_OK) == 0 && dir == NULL) {
        process_fork(sh, sh->av[0]);
        return;
    }
    if (access(&sh->av[0][2], F_OK) != 0 && cm_strcmp("./", sh->av[0]) != 0) {
        cm_putstr(sh->av[0]);
        cm_putstr(": Command not found.\n");
        sh->ret = 1;
        return;
    }
    cm_putstr(sh->av[0]);
    cm_putstr(": Permission denied.\n");
    sh->ret = 1;
    closedir(dir);
}

int exec_in_delivery(shell_t *sh)
{
    if (sh->av[0][0] == '.' && sh->av[0][1] == '.' && sh->av[0][2] == '/') {
        if (access(sh->av[0], X_OK) == 0) {
            process_fork(sh, sh->av[0]);
        } else {
            cm_putstr(sh->av[0]);
            cm_putstr(": Command not found.\n");
            sh->ret = 1;
        }
        return 0;
    }
    for (int i = 0; sh->av[0][i]; i++) {
        if (sh->av[0][i] == '/' && access(sh->av[0], X_OK) == 0) {
            process_fork(sh, sh->av[0]);
            return 0;
        }
    }
    return 1;
}
