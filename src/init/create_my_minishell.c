/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** create_my_minishell
*/

#include "../../include/minishell.h"

line_t *init_struct_line(void)
{
    line_t *struct_line = malloc(sizeof(line_t));

    struct_line->history_head = NULL;
    struct_line->current_history = NULL;
    struct_line->index = 0;
    struct_line->len = 0;
    struct_line->buffer = '\0';
    memset(struct_line->string, '\0', 1024);
    return (struct_line);
}

void create_my_minishell_two(my_minishell_t *my_minishell)
{
    my_minishell->exit = 0;
    my_minishell->previous_exit = 0;
    my_minishell->error = 0;
    my_minishell->end = 0;
    my_minishell->pos = malloc(sizeof(my_path_t));
    my_minishell->pos->home = NULL;
    my_minishell->pos->path = NULL;
    my_minishell->len = 0;
    my_minishell->err = 0;
    my_minishell->oldfd = 1;
    my_minishell->command_line = NULL;
    my_minishell->dup_zero = dup(0);
    my_minishell->dup_one = dup(1);
    my_minishell->last_path = NULL;
    my_minishell->struct_line = init_struct_line();
    my_minishell->struct_alias = NULL;
    my_minishell->struct_set = NULL;
    my_minishell->dollar_index = 0;
    my_minishell->last_pid = 0;
}

my_minishell_t *create_my_minishell(char **env)
{
    my_minishell_t *my_minishell = malloc(sizeof(my_minishell_t));
    my_minishell->env = env;
    my_minishell->my_env = create_my_env(env);
    create_my_minishell_two(my_minishell);
    initialize_pwd(my_minishell);
    return (my_minishell);
}
