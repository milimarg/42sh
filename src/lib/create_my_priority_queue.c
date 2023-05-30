/*
** EPITECH PROJECT, 2023
** ANT_GIANT
** File description:
** create_my_priority_queue
*/


#include "my.h"

queue_t *create_a_queue_node(int data, int symb, int total)
{
    queue_t *queue = malloc(sizeof(queue_t));
    if (!queue)
        return (NULL);
    queue->node = my_node(data, symb, total);
    if (!queue->node)
        return (NULL);
    queue->next = malloc(sizeof(queue_t));
    if (!queue->next)
        return (NULL);
    queue->next = NULL;
    return (queue);
}

queue_t *create_my_priority_queue(int *symb_tab, int total)
{
    int *low = lowest_in_int_tab(symb_tab);
    queue_t *queue = create_a_queue_node(low[0], low[1], total);
    if (!queue)
        return (NULL);
    queue_t *root = queue;
    if (!root)
        return (NULL);
    low = lowest_in_int_tab(symb_tab);
    while (low[0] != 0) {
        queue->next = create_a_queue_node(low[0], low[1], total);
        if (!queue->next)
            return (NULL);
        queue = queue->next;
        low = lowest_in_int_tab(symb_tab);
    }
    return (root);
}
