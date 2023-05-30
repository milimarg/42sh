/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_unset
*/

#include "../../include/minishell.h"

static variable_t *remove_unset(char **all_command,
my_minishell_t *my_minishell, int i, variable_t *temp)
{
    variable_t *temp_var = temp->next;

    if (my_strcmp(all_command[i], temp->name) == 0) {
        remove_double_set(&my_minishell->struct_set, temp->name);
        return temp_var;
    }
    temp = temp->next;
    return temp;
}

int my_unset(char **all_command, my_minishell_t *my_minishell)
{
    if (all_command[1] == NULL) {
        write(2, "unset: Too few arguments.\n", 26);
        return (1);
    }
    for (int i = 1; all_command[i]; i++) {
        for (variable_t *temp = my_minishell->struct_set; temp != NULL;)
            temp = remove_unset(all_command, my_minishell, i, temp);
    }
    return (0);
}
