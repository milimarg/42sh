/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** free_my_minishell
*/

#include "../../include/minishell.h"

void free_my_env(my_minishell_t *my_minishell)
{
    my_env_t *temp = my_minishell->my_env;

    for (; my_minishell->my_env != NULL; my_minishell->my_env = temp) {
        temp = my_minishell->my_env->next;
        free_my_env_node(my_minishell->my_env);
    }
}

void free_history(history_t *head)
{
    history_t *temp = head;

    for (; head != NULL; head = temp) {
        temp = head->next;
        free(head);
    }
}

void free_struct_line(line_t *struct_line)
{
    if (!struct_line)
        return;
    free_history(struct_line->history_head);
    struct_line->history_head = NULL;
    struct_line->current_history = NULL;
    free(struct_line);
}

void free_pos(my_path_t *pos)
{
    if (!pos)
        return;
    if (pos->pwd)
        free(pos->pwd);
    if (pos->oldpwd)
        free(pos->oldpwd);
    free(pos);
}

void free_my_minishell(my_minishell_t *my_minishell)
{
    if (!isatty(0))
        return;
    free_my_env(my_minishell);
    free_struct_line(my_minishell->struct_line);
    if (my_minishell->command_line)
        free(my_minishell->command_line);
    free_pos(my_minishell->pos);
    free_my_tab(my_minishell->last_path);
    if (my_minishell->argu)
        free_my_tab(my_minishell->argu);
    if (my_minishell->struct_alias)
        free_struct_alias(my_minishell->struct_alias);
    free(my_minishell);
}
