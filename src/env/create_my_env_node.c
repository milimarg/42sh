/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** create_my_env_node
*/

#include "../../include/minishell.h"

my_env_t *create_my_env_node(char **tab, int status)
{
    my_env_t *tmp = malloc(sizeof(my_env_t));
    tmp->name = my_strdup(tab[0]);
    if (tab[1] != NULL) {
        char *temp = my_strdup(tab[1]);
        for (int i = 2; tab[i] != NULL; i++) {
            temp = my_strcat(temp, "=");
            temp = my_strcat(temp, tab[i]);
        }
        tmp->path = my_str_to_word_array_spe(temp, ':');
        tmp->variable = my_strdup(temp);
        free(temp);
    } else {
        tmp->path = malloc(sizeof(char *));
        tmp->path[0] = NULL;
        tmp->variable = NULL;
    }
    tmp->next = NULL;
    tmp->status = status;
    return (tmp);
}
