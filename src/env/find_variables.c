/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** find_variables
*/

#include "../../include/minishell.h"

char *find_in_env(char *str, my_minishell_t *min)
{
    my_env_t *temp = min->my_env;

    for (; temp != NULL; temp = temp->next)
        if (my_strcmp(str, temp->name) == 0)
            break;
    if (temp == NULL)
        return (NULL);
    if (my_strlen(temp->name) == 0)
        return (strdup(""));
    return (temp->variable);
}

char *find_in_local_var(char *str, my_minishell_t *min)
{
    variable_t *temp = min->struct_set;

    for (; temp != NULL; temp = temp->next)
        if (my_strcmp(str, temp->name) == 0)
            break;
    if (temp == NULL)
        return (NULL);
    if (my_strlen(temp->name) == 0)
        return (strdup(""));
    return (temp->value);
}
