/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** unset_my_env
*/

#include "../../include/minishell.h"

int error_handling_unsetenv(my_env_t *tmp, char **all_command)
{
    if (tmp == NULL) {
        return (1);
    }
    return (0);
}

void remove_my_node(my_minishell_t *min, my_env_t *to_remove)
{
    my_env_t *tmp = min->my_env;
    my_env_t *previous = min->my_env;
    for (; my_strncmp(tmp->name, to_remove->name,
        my_strlen(to_remove->name)) != 0; tmp = tmp->next) {
        previous = tmp;
    }
    if (tmp == min->my_env) {
        min->my_env = tmp->next;
        free_my_env_node(previous);
    } else {
        previous->next = tmp->next;
        free_my_env_node(tmp);
    }
    return;
}

int unset_my_env(char **all_command, my_minishell_t *my_minishell)
{
    if (all_command[1] == NULL) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return (0);
    }
    for (int i = 1; all_command[i] != NULL; i++) {
        my_env_t *tmp = my_minishell->my_env;
        for (; tmp != NULL && my_strncmp(tmp->name,
            all_command[i], my_strlen(all_command[i])) != 0; tmp = tmp->next);
        if (error_handling_unsetenv(tmp, all_command) == 0)
            remove_my_node(my_minishell, tmp);
    }
    return (0);
}
