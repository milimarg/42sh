/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** ignore_space_and_tabs
*/

#include "../../include/minishell.h"

int ignore_space_and_tabs(int i, char const *str)
{
    if ((str[i] == ' ' || str[i] == '\t')) {
        while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t')) {
            i++;
        }
        return (i - 1);
    }
    return (i);
}
