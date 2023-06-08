/*
** EPITECH PROJECT, 2023
** process.c
** File description:
** BY - CM
*/

#include "shell.h"

void process_fork(shell_t *sh, char *filepath)
{
    pid_t child = fork();
    int sta = 0;

    if (child == -1)
        exit(84);
    if (child == 0) {
        execve(filepath, sh->av, sh->env);
        cm_putstr(sh->av[0]);
        cm_putstr(": Permission denied.\n");
        exit(EXIT_FAILURE);
    } else {
        waitpid(child, &sta, 0);
        sh->ret = WEXITSTATUS(sta);
        if (WIFSIGNALED(sta))
            check_signal(sh, sta);
    }
}

int check_arg(shell_t *sh)
{
    if (cm_strcmp(sh->av[0], "exit") == 0) {
        write(1, "exit\n", 6);
        exit(0);
    } else if (cm_strcmp(sh->av[0], "cd") == 0) {
        command_cd(sh);
        return 0;
    }
    if (cm_strcmp(sh->av[0], "setenv") == 0) {
        command_setenv(sh);
        return 0;
    }
    if (cm_strcmp(sh->av[0], "unsetenv") == 0) {
        commant_unsetenv(sh);
        return 0;
    }
    if (cm_strcmp(sh->av[0], "env") == 0) {
        command_env(sh);
        return 0;
    }
    return 1;
}

void process_arg(shell_t *sh)
{
    char *filepath = NULL;
    char **new_env = NULL;

    sh->ret = 0;
    if (check_arg(sh) == 0)
        return;
    if (sh->av[0][0] == '.' && sh->av[0][1] == '/') {
        check_access(sh);
        return;
    }
    if (exec_in_delivery(sh) == 0)
        return;
    new_env = pars_env(sh->env, "PATH");
    filepath = get_access(sh, new_env);
    if (filepath != NULL) {
        process_fork(sh, filepath);
        free(filepath);
    }
    cm_freetab(new_env);
}

int is_isatty(shell_t *sh)
{
    int ret = 0;

    if (isatty(0) == 1) {
        cm_putstr("exit\n");
    }
    ret = sh->ret;
    free_struct(sh);
    return ret;
}

int process(char **env)
{
    shell_t *sh = malloc(sizeof(shell_t));
    size_t size = 0;
    int ret = 0;

    init_shell(sh);
    sh->env = tab_in_tab(env);
    while (1) {
        if (isatty(0) == 1)
            cm_prompt(sh);
        if (getline(&sh->lineptr, &size, stdin) < 0) {
            ret = is_isatty(sh);
            return ret;
        }
        sh->av = cm_str_to_word_array(sh->lineptr);
        if (sh->av[0] == NULL)
            continue;
        process_arg(sh);
        cm_freetab(sh->av);
    }
}
