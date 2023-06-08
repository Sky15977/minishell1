/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** dico func
*/

#include <stdio.h>

#include "my_lib.h"
#include <dirent.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef MINISHELL_H
    #define MINISHELL_H

    typedef struct shell_s {
        int ret;
        char *pwd;
        char *pwd_previous;
        char *lineptr;
        char **av;
        char **env;
    } shell_t;

//cd.c
    void cd_previous(shell_t *sh);
    void cd_back(shell_t *sh);
    void cd_after(shell_t *sh);
    int first_command_cd(shell_t *sh, unsigned int y);
    void command_cd(shell_t *sh);

//cd_bis.c
    void change_pwd(shell_t *sh, char **tab, char *filepath);
    void cd_with_path(shell_t *sh);
    void cd_basics(shell_t *sh);

//check.c
    int error_setenv(shell_t *sh, char const *str);
    int check_directory(shell_t *sh);
    void check_pwd_previous(shell_t *sh);
    void check_access(shell_t *sh);
    int exec_in_delivery(shell_t *sh);

//cm_prompt.c
    void cm_prompt(shell_t *sh);

//env.c
    void command_env(shell_t *sh);

//get.c
    char *get_access(shell_t *sh, char **env);
    char *get_pathback(shell_t *sh);
    char *get_pwd(shell_t *sh);
    char *concat_filepath(char *filepath, char *str);

//init.c
    char **tab_in_tab(char **tab);
    void init_shell(shell_t *sh);

//process.c
    void process_fork(shell_t *sh, char *filepath);
    int check_arg(shell_t *sh);
    void process_arg(shell_t *sh);
    int is_isatty(shell_t *sh);
    int process(char **env);

//setenv.c
    void concat_new_line(shell_t *sh, char *str, int y);
    void line_new(shell_t *sh, char **tab, int y);
    void line_exist(shell_t *sh, int i);
    void add_line_env(shell_t *sh, char **tab);
    void command_setenv(shell_t *sh);

//signal.c
    void check_signal(shell_t *sh, int nb);

//unsetenv.c
    void line_delete(shell_t *sh, char **tab, int y, int i);
    void delete_line_env(shell_t *sh, char **tab);
    void commant_unsetenv(shell_t *sh);

//error.c
    void free_struct(shell_t *sh);
    int manage_error(void);
    int manage_usage(void);

//main.c
    char **pars_env(char **env, char *str);

#endif /* MINISHELL */
