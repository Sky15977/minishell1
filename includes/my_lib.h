/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** lib
*/

#ifndef MY_LIB_H
    #define MY_LIB_H

    #define TRUE (1)
    #define FALSE (0)
    #define ERROR (84)
    #define SUCESS (0)
    #define UINT unsigned int

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stddef.h>

    typedef struct list_node_s {
        void *value;
        struct list_node_s *next;
        struct list_node_s *prev;
    } list_node_t;

    typedef struct list_s {
        list_node_t *head;
        list_node_t *tail;
        unsigned int size;
    } list_t;

    /**
     * write N for number <0, write P for number >=0
     * @param int
     * @return int
    */
    int cm_isneg(int nb);

//list_add.c
    unsigned int list_add(list_t *list, void *value);
    list_t *list_create(void);

//list_get.c
    void *list_get_node(list_t *list, unsigned int index);
    void *list_get(list_t *list, unsigned int index);
    void list_remove(list_t *list, unsigned int index);


/* INT */

    /**
     * transform a string in a int.
     * @param char const *
     * @return int
    */
    int cm_getnbr(char const *str);
    /**
     * #include <unistd.h> --
     * Write a int in output (1).
     * @param int a number to write
     * @return UINT
    */
    unsigned int cm_putnbr(int nb);
    /**
     * #include <unistd.h> --
     * Write a int in output (1).
     * @param int a number to write
     * @return UINT
    */
    unsigned int cm_putnbr_base(int nbr, char const *base);
    /**
     * Swap two number.
     * @param int
     * @return void
    */
    void cm_swap(int *a, int *b);


/* LIST */



/* CHAR */

    /**
     * #include <unistd.h> --
     * Write a single charactere in output (1).
     * @param char a charactere to write
     * @return void
    */
    void cm_putchar(char c);
    /**
     * #include <unistd.h> --
     * Write a single charactere in output error (2).
     * @param char a charactere to write
     * @return void
    */
    void cm_putchar_error(char c);


/* STR */

    /**
     * #include <unistd.h> --
     * Write a string in output (1).
     * @param char* a string to write
     * @return void
    */
    void cm_putstr(char const *str);
    /**
     * #include <unistd.h> --
     * Write a string in output error (2).
     * @param char* a string to write
     * @return void
    */
    void cm_putstr_error(char const *str);
    char *cm_revstr(char *str);
    /**
     * #include <stdlib.h> --
     * transform a char* in char** has each space or '\'.
     * @param char*
     * @return char**
    */
    char **cm_str_to_word_array(char const *str);
    char *cm_strcat(char *dest, char const *src);
    char *cm_strncat(char *dest, char const *src, UINT n);
    int cm_strcmp(char const *s1, char const *s2);
    int cm_strncmp(char const *s1, char const *s2, UINT n);
    char *cm_strcpy(char *dest, char const *src);
    char *cm_strncpy(char *dest, char const *src, UINT n);
    char *cm_strdup(char const *src);
    unsigned int cm_strlen(char const *str);
    /**
     * #include <stdlib.h> --
     * transform a char* in char** has each separator or '\'.
     * @param char* str -> the string has separted
     * @param char** sep -> every separator you want
     * @return char**
    */
    char **cm_strtok(char const *str, char const *sep);
    /**
     * transform the lowercase to upercase
     * @param char*
     * @return char *
    */
    char *cm_strupcase(char *str);

            //cm_stris.c
    int cm_str_isalpha(char const *str);
    int cm_str_islower(char const *str);
    int cm_str_isnum(char const *str);
    int cm_str_isprintable(char const *str);
    int cm_str_isupper(char const *str);


/* TAB */

    /**
     * free the memorys of a tab
     * @param char**
     * @return void
    */
    void cm_freetab(char **tab);
    /**
     * #include <unistd.h> --
     * Write several strings in the output (1).
     * @param char** several string to write
     * @return void
    */
    void cm_puttab(char **tab);
    /**
     * #include <unistd.h> --
     * Write several strings in the output error (2).
     * @param char** several string to write
     * @return void
    */
    void cm_puttab_error(char **tab);

#endif
