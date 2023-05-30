/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** print_my_env
*/

#include "../../include/minishell.h"

int print_my_env(char **all_command, my_minishell_t *my_minishell)
{
    my_env_t *my_env = my_minishell->my_env;
    my_env_t *tmp = my_env;

    while (tmp != NULL) {
        my_printf("%s=", tmp->name);
        int i = 0;
        while (tmp->path != NULL && tmp->path[i] != NULL) {
            my_printf("%s", (i > 0) ? ":" : "");
            my_printf("%s",tmp->path[i]);
            i++;
        }
        my_printf("\n");
        tmp = tmp->next;
    }
    return (0);
}
