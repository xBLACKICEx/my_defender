/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** linked_list
*/

#ifndef linked_list_H_
#define linked_list_H_

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef enum STRUCT_NAME_e {
    S_NILL = -1,
    S_WALNUT,
    S_SUN,
    S_PEA,
    S_BEEF,
    S_MINI_MAP,
    S_Z1,
    S_Z2
} STRUCT_NAME_t;

typedef struct node_s node_t;
struct node_s {
    STRUCT_NAME_t name;
    void *data;
    node_t *prev;
    node_t *next;
};

typedef struct dlist_s dlist_t;
struct dlist_s {
    node_t *begin;
    node_t *end;
    unsigned int len;
};

void rr(dlist_t **list, node_t *node_1, node_t *node_2);
void sa(dlist_t **list, node_t *node_1, node_t *node_2);
void sb(dlist_t **list, node_t *node_1, node_t *node_2);
void swap_nodes(dlist_t **list, node_t *node_1, node_t *node_2);
void swap_center(dlist_t **list, node_t *node_1, node_t *node_2);

int dlist_length(dlist_t *cout_tota_list);
void print_dlist_begin(dlist_t *list);
void print_dlist_end(dlist_t *list);
bool is_empty_dlist(dlist_t *ccheak_list_is_null);
void push_back(dlist_t **dlist, void *data, STRUCT_NAME_t name);
void push_front(dlist_t **dlist, void *data, STRUCT_NAME_t name);
void clear_dlist(dlist_t **dlist, void (*free_node)(node_t *));
void pop_front(dlist_t **dlist, void (*free_node)(node_t *));
void pop_center(dlist_t **dlist, node_t *node, void (*free_node)(node_t *));
void pop_list(dlist_t **dlist, void *data, bool (*cmp)(node_t *, void *),
            void (*free_node)(node_t *));
void pop_back(dlist_t **dlist, void (*free_node)(node_t *));
void free_data(void *data_list);
void free_node(node_t *node);

#endif
