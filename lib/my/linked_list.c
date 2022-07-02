/*
** EPITECH PROJECT, 2022
** lib
** File description:
** linked_list
*/

#include "linked_list.h"
#include <stddef.h>
#include <stdlib.h>

linked_list_t *create_list(void *data)
{
    linked_list_t *list = malloc(sizeof(linked_list_t));

    list->data = data;
    list->next = NULL;
    return list;
}

linked_list_t *add_node(linked_list_t *list, void *data)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));
    linked_list_t *head = list;

    node->data = data;
    node->next = NULL;
    while (list->next != NULL) {
        list = list->next;
    }
    list->next = node;
    return head;
}

linked_list_t *add_end_node(linked_list_t *list, void *data)
{
    if (list == NULL) {
        list = create_list(data);
        return list;
    }
    list = add_node(list, data);
    return list;
}

int len_list(linked_list_t *list)
{
    int len = 0;

    while (list != NULL) {
        len++;
        list = list->next;
    }
    return len;
}

linked_list_t *remove_first_node(linked_list_t *list)
{
    linked_list_t *tmp = list;

    list = list->next;
    free(tmp);
    return list;
}
