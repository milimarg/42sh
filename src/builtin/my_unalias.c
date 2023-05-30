/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_unalias
*/

#include "../../include/minishell.h"

static alias_t *remove_alias(char **all_command, my_minishell_t *my_minishell,
int i, alias_t *temp)
{
    alias_t *temp_alias = NULL;

    if (my_strcmp(all_command[i], temp->name) == 0) {
        remove_double(&my_minishell->struct_alias, temp->name);
        return temp_alias;
    }
    temp = temp->next;
    return temp;
}

int my_unalias(char **all_command, my_minishell_t *my_minishell)
{
    if (all_command[1] == NULL) {
        write(2, "unalias: Too few arguments.\n", 28);
        return (1);
    }
    for (int i = 1; all_command[i]; i++) {
        for (alias_t *temp = my_minishell->struct_alias; temp != NULL;)
            temp = remove_alias(all_command, my_minishell, i, temp);
    }
    return (0);
}
