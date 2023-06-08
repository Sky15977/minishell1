/*
** EPITECH PROJECT, 2023
** error.c
** File description:
** BY - CM
*/

#include "shell.h"

void free_struct(shell_t *sh)
{
    cm_freetab(sh->env);
    free(sh->pwd_previous);
    free(sh->lineptr);
    free(sh);
}

int manage_error(void)
{
    cm_putstr("./mysh: bad arguments\n");
    cm_putstr("retry with -h\n");
    exit(84);
}

int manage_usage(void)
{
    cm_putstr("USAGE\n   ./mysh\n\n");
    cm_putstr("OPTIONS\n   -h\tprint the usage and quit.\n");
    cm_putstr("   \tbut no option, just ./mysh\n\n");
    exit(0);
}
