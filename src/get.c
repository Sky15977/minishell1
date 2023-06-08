/*
** EPITECH PROJECT, 2023
** get.c
** File description:
** BY - CM
*/

#include "shell.h"

char *get_access(shell_t *sh, char **env)
{
    char *filepath = NULL;

    if (sh->av[0][0] == '/') {
        filepath = cm_strdup(sh->av[0]);
        return filepath;
    }
    for (int y = 0; env[y] != NULL; y++) {
        if (y == 0) {
            filepath = concat_filepath(&env[y][5], sh->av[0]);
        } else
            filepath = concat_filepath(env[y], sh->av[0]);
        if (access(filepath, X_OK) == 0) {
            return filepath;
        }
        free(filepath);
    }
    cm_putstr(sh->av[0]);
    cm_putstr(": Command not found.\n");
    sh->ret = 1;
    return NULL;
}

char *get_pathback(shell_t *sh)
{
    char *pathback = NULL;
    int i = 0;
    int j = 0;

    for (; sh->pwd_previous[i]; i++)
        if (sh->pwd_previous[i] == '/') {
            j = i;
        }
    if (j == 0)
        return pathback = cm_strdup("/\0");
    pathback = malloc(sizeof(char) * (j + 1));
    for (i = 0; i < j; i++) {
        pathback[i] = sh->pwd_previous[i];
    }
    pathback[i] = '\0';
    return pathback;
}

char *get_pwd(shell_t *sh)
{
    int a = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    char *path = NULL;

    for (; sh->env[y]; y++) {
        for (x = 0; sh->env[y][x] != '=' && sh->env[y][x]; x++);
        if (cm_strncmp("PWD", sh->env[y], x) == 0) {
            i = y;
            a = x + 1;
        }
    }
    if (i != 0) {
        path = cm_strdup(&sh->env[i][a]);
    } else {
        cm_putstr("PWD not find !\n");
        path = cm_strdup("not/find");
    }
    return path;
}

char *concat_filepath(char *filepath, char *str)
{
    int nb = cm_strlen(filepath);
    char *res = malloc(sizeof(char) * (nb + cm_strlen(str) + 2));
    int i = 0;

    for (; filepath[i] != '\0'; i++)
        res[i] = filepath[i];
    if (res[i - 1] != '/') {
        res[i] = '/';
        i = i + 1;
    }
    for (int j = 0; str[j] != '\0'; j++) {
        res[i] = str[j];
        i++;
    }
    res[i] = '\0';
    return res;
}
