/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** create_my_env
*/

#include "../../include/minishell.h"

my_env_t *create_my_env(char **env)
{
    char **tmp = my_str_to_word_array_spe(env[0], '=');
    my_env_t *my_env = create_my_env_node(tmp, 0);
    my_env_t *root = my_env;
    free_my_tab(tmp);
    for (int i = 1; env[i] != NULL; i++) {
        char **tab = my_str_to_word_array_spe(env[i], '=');
        root->next = create_my_env_node(tab, 0);
        free_my_tab(tab);
        root = root->next;
    }
    return (my_env);
}
