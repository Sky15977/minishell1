/*
** EPITECH PROJECT, 2023
** cm_strtok.c
** File description:
** str_to_word_array_cm
*/

#include "my_lib.h"

static int is_separator(char a, char const *sep)
{
    for (UINT i = 0; sep[i]; i++)
        if (a == sep[i] || (a > 6 && a < 14))
            return TRUE;
    return FALSE;
}

static unsigned int len_of_word(char const *str, char const *sep)
{
    UINT i = 0;

    for (; str[i]; i++)
        if (is_separator(str[i], sep) != FALSE)
            return i;
    return i;
}

static unsigned int nb_word(char const *str, char const *sep)
{
    UINT i = 0;
    UINT nb = 0;

    for (; str[i]; i++) {
        if (is_separator(str[i], sep) != TRUE &&
        (is_separator(str[i + 1], sep) || str[i + 1] == '\0'))
            nb++;
    }
    return nb;
}

char **cm_strtok(char const *str, char const *sep)
{
    UINT nb = nb_word(str, sep);
    UINT i = 0;
    UINT y = 0;
    UINT x = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (nb + 1));
    tab[nb] = NULL;
    for (; y < nb; i++) {
        for (; is_separator(str[i], sep) != FALSE && str[i]; i++);
        tab[y] = malloc(sizeof(char) * (len_of_word(&str[i], sep) + 1));
        for (x = 0; is_separator(str[i], sep) != TRUE && str[i]; i++) {
            tab[y][x] = str[i];
            x++;
        }
        tab[y][x] = '\0';
        y++;
    }
    return tab;
}
