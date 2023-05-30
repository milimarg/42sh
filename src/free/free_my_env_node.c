/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** free_my_env_node
*/

#include "../../include/minishell.h"

void free_my_env_node(my_env_t *node)
{
    free(node->name);
    if (node->path != NULL) {
        for (int i = 0; node->path[i] != NULL; i++) {
            free(node->path[i]);
        }
        free(node->path);
    }
    free(node);
}
