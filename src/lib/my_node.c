/*
** EPITECH PROJECT, 2023
** my_node
** File description:
** antman
*/

#include "my.h"

node_t* my_node(int data, char symb, int total)
{
    node_t* node = malloc(sizeof(node_t));
    if (!node)
        return (NULL);
    node->occurence = data;
    node->symb = symb;
    node->total = total;
    node->pourcent = ((float)data * 100) / (float) total;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
