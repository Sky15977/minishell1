/*
** EPITECH PROJECT, 2023
** my_str_to_word_array.c
** File description:
** BY - CM
*/

#include "my_lib.h"

static int is_separator(char a)
{
    if (a == ' ' || (a > 6 && a < 14))
        return TRUE;
    else
        return FALSE;
}

static unsigned int len_of_word(char const *str)
{
    UINT i = 0;

    for (; str[i]; i++)
        if (is_separator(str[i]) != FALSE)
            return i;
    return i;
}

static unsigned int nb_word(char const *str)
{
    UINT i = 0;
    UINT nb = 0;

    for (; str[i]; i++) {
        if (is_separator(str[i]) == FALSE && is_separator(str[i + 1]))
            nb++;
    }
    return nb;
}

char **cm_str_to_word_array(char const *str)
{
    UINT nb = nb_word(str);
    UINT i = 0;
    UINT y = 0;
    UINT x = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (nb + 1));
    tab[nb] = NULL;
    for (; y < nb; i++) {
        for (; is_separator(str[i]) != FALSE; i++);
        tab[y] = malloc(sizeof(char) * (len_of_word(&str[i]) + 1));
        for (x = 0; is_separator(str[i]) != TRUE; i++) {
            tab[y][x] = str[i];
            x++;
        }
        tab[y][x] = '\0';
        y++;
    }
    return tab;
}
