/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** free_my_tab
*/

#include "../../include/minishell.h"

void free_my_tab(char **tab)
{
    if (!tab)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        if (tab[i] != NULL)
            free(tab[i]);
    }
    if (tab != NULL)
        free(tab);
}
