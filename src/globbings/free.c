/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** free.c
*/

#include "../../include/minishell.h"

void free_globbings(char **argv, int *matches)
{
    free_my_tab(argv);
    free(matches);
}
