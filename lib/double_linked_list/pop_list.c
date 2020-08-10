/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** pop_list
*/

#include <linked_list.h>
#include <my_tools.h>

void pop_front(dlist_t **dlist, void (*free_node)(node_t *))
{
    node_t *tmp;
    if (is_empty_dlist(*dlist) == true) return;
    if ((*dlist)->len == 1) {
        free_node((*dlist)->begin);
        free((*dlist));
        (*dlist) = NULL;
        return;
    } else {
        tmp = (*dlist)->begin;
        (*dlist)->begin = (*dlist)->begin->next;
        (*dlist)->begin->prev = NULL;
        free_node(tmp);
    }
    (*dlist)->len -= 1;
}

void pop_center(dlist_t **dlist, node_t *node, void (*free_node)(node_t *))
{
    if ((*dlist) == NULL || (*dlist)->begin == NULL || node == NULL) return;
    if (node == (*dlist)->begin) {
        pop_front(dlist, free_node);
        return;
    } else if (node == (*dlist)->end) {
        pop_back(dlist, free_node);
        return;
    } else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free_node(node);
        (*dlist)->len--;
        return;
    }
}

void pop_list(dlist_t **dlist, void *data, bool (*cmp)(node_t *, void *),
                void (*free_node)(node_t *))
{
    if ((*dlist) != NULL && (*dlist)->begin != NULL) {
        for (node_t *tmp = (*dlist)->begin; tmp != NULL; tmp = tmp->next) {
            if ((*cmp)(tmp, data) == true) {
                pop_center(dlist, tmp, free_node);
                pop_list(dlist, data, cmp, free_node);
                return;
            }
        }
    }
}

void pop_back(dlist_t **dlist, void (*free_node)(node_t *))
{
    node_t *tmp;
    if (is_empty_dlist(*dlist) == true) return;
    if ((*dlist)->len == 1) {
        free_node((*dlist)->end);
        free((*dlist));
        (*dlist) = NULL;
        return;
    } else {
        tmp = (*dlist)->end;
        (*dlist)->end = (*dlist)->end->prev;
        (*dlist)->end->next = NULL;
        free_node(tmp);
    }
    (*dlist)->len -= 1;
}