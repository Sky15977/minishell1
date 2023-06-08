/*
** EPITECH PROJECT, 2022
** main
** File description:
** BY - CM
*/

#include "shell.h"

char **pars_env(char **env, char *str)
{
    char **tab = NULL;

    for (int y = 0; env[y] != NULL; y++) {
        if (cm_strncmp(env[y], str, 3) == 0)
            tab = cm_strtok(env[y], ":");
    }
    return tab;
}

int main(int ac, char **av, char **env)
{
    if (ac == 2 && (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == 0))
        manage_usage();
    if (ac > 1)
        manage_error();
    return process(env);
}
