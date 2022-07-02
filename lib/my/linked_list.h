/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-florian.garde
** File description:
** linked_list
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

linked_list_t *create_list(void *data);
linked_list_t *add_node(linked_list_t *list, void *data);
linked_list_t *remove_first_node(linked_list_t *list);
linked_list_t *add_end_node(linked_list_t *list, void *data);
int len_list(linked_list_t *list);

#endif /* !LINKED_LIST_H_ */
