/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** set_my_env
*/

#include "../../include/minishell.h"

int error_handling_setenv_two(char **my_infos, my_minishell_t *my_minishell)
{
    int is_alpha = 0;
    for (int i = 0; my_infos[0][i] != '\0'; i++) {
        if ((my_infos[0][i] >= 0 && my_infos[0][i] <= 64) ||
            (my_infos[0][i] >= 91 && my_infos[0][i] <= 96) ||
            (my_infos[0][i] >= 123 && my_infos[0][i] <= 127)) {
            write(2 ,
            "setenv: Variable name must contain alphanumeric characters.\n",60);
            return (1);

            }
    }
    return (0);
}

int error_handling_setenv(char **my_infos, my_minishell_t *my_minishell)
{
    if (my_infos[0] == NULL) {
        print_my_env(NULL, my_minishell);
        return (1);
    }
    if (my_infos[0][0] != '_') {
        if ((my_infos[0][0] >= 0 && my_infos[0][0] <= 64) ||
            (my_infos[0][0] >= 91 && my_infos[0][0] <= 96) ||
            (my_infos[0][0] >= 123 && my_infos[0][0] <= 127)) {
            write (2, "setenv: Variable name must begin with a letter.\n", 48);
            return (1);
        }
    }
    return (error_handling_setenv_two(my_infos, my_minishell));
}

int set_my_env_two(my_minishell_t *my_minishell, char **my_infos, char **all)
{
    my_env_t *tmp = my_minishell->my_env;
    my_env_t *previous = NULL;
    for (; tmp->next != NULL && my_strncmp(tmp->name, all[1],
        my_strlen(all[1])) != 0; tmp = tmp->next)
        previous = tmp;
    if (my_strncmp(tmp->name, all[1], my_strlen(all[1])) == 0) {
        my_env_t *next = tmp->next;
        my_env_t *new = create_my_env_node(my_infos, 1);
        if (previous != NULL)
            previous->next = new;
        else
            my_minishell->my_env = new;
        new->next = next;
        free_my_env_node(tmp);
    } else {
        tmp->next = create_my_env_node(my_infos, 1);
    }
}

int set_my_env(char **all_command, my_minishell_t *my_minishell)
{
    int i = 0;
    for (; all_command[i] != NULL; i++);
    char **my_infos = malloc(sizeof(char *) * i);
    for (int j = 0; j < i - 1; j++) {
        my_infos[j] = all_command[j + 1];
    }
    if (i > 3) {
        write (2, "setenv: Too many arguments.\n", 28);
        return (1);
    }
    my_infos[i - 1] = NULL;
    int error = error_handling_setenv(my_infos, my_minishell);
    if (error == 0) {
        set_my_env_two(my_minishell, my_infos, all_command);
        return (0);
    } else {
        return (error);
    }
}
