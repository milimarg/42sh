/*
** EPITECH PROJECT, 2023
** create_my_binary
** File description:
** antman
*/

#include "my.h"

queue_t *replace_in_queue(queue_t *actual, queue_t *to_place)
{
    queue_t *root = actual;
    queue_t *prev = NULL;
    while (actual->node->occurence <= to_place->node->occurence &&
        actual->next != NULL) {
        prev = actual;
        actual = actual->next;
    }
    if (actual->next == NULL) {
        to_place->next = NULL;
        actual->next = to_place;
    } else {
        to_place->next = actual;
        prev->next = to_place;
    }
    return (root);
}

node_t *node_final(queue_t *final, int total)
{
    if (final->next != NULL) {
        node_t *one = final->node;
        queue_t *temp = final;
        final = final->next;
        free(temp);
        node_t *two = final->node;
        temp = final;
        final = final->next;
        free(temp);
        queue_t *parent = create_a_queue_node(one->occurence + two->occurence,
        0, total);
        parent->node->left = one;
        parent->node->right = two;
        node_t *result = parent->node;
        return (result);
    }
    return (final->node);
}

node_t *create_my_binary_tree(queue_t *queue, int total)
{
    while (queue->next->next != NULL) {
        node_t *one = queue->node;
        queue_t *temp = queue;
        queue = queue->next;
        free(temp);
        node_t *two = queue->node;
        temp = queue;
        queue = queue->next;
        free(temp);
        queue_t *parent = create_a_queue_node(one->occurence + two->occurence,
        0, total);
        parent->node->left = one;
        parent->node->right = two;
        queue = replace_in_queue(queue, parent);
    }
    node_t *result = node_final(queue, total);
    return (result);
}
