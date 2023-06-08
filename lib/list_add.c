/*
** EPITECH PROJECT, 2022
** list_v2.c
** File description:
** v2
*/

#include "my_lib.h"

list_t *list_create(void)
{
    list_t *list = malloc(sizeof(list_t));

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

static unsigned int list_add_node(list_t *list, list_node_t *node)
{
    list->size++;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        return 0;
    }
    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
    return list->size - 1;
}

unsigned int list_add(list_t *list, void *value)
{
    list_node_t *node;

    if (list == NULL || value == NULL) {
        printf("list_add: value & list = NULL");
        return 0;
    }
    node = malloc(sizeof(list_node_t));
    node->value = value;
    node->next = NULL;
    node->prev = NULL;
    return list_add_node(list, node);
}
