/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** is_builtin
*/

#include "../../include/minishell.h"

int is_builtin(char *command)
{
    for (int i = 0; BUILTIN_TAB[i]; i++)
        if (my_strcmp(command, BUILTIN_TAB[i]) == 0)
            return (1);
    return (0);
}
