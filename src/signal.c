/*
** EPITECH PROJECT, 2023
** signal.c
** File description:
** BY - CM
*/

#include "shell.h"

void check_signal(shell_t *sh, int status)
{
    if (WTERMSIG(status) == SIGFPE) {
        cm_putstr_error("Floating exception");
        sh->ret = 136;
    } else if (WTERMSIG(status) == SIGSEGV) {
        cm_putstr_error("Segmentation fault");
        sh->ret = 139;
    } else {
        cm_putstr_error(strsignal(WTERMSIG(status)));
        sh->ret = 1;
    }
    if (WCOREDUMP(status))
        cm_putstr_error(" (core dumped)");
    cm_putchar('\n');
}
