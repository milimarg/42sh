/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** loop_minishell
*/

#include "../include/minishell.h"

void separate_command(my_minishell_t *my_minishell)
{
    if (my_minishell->err != -1
    && not_only_space(my_minishell->command_line) == 0 &&
        check_unmatched(my_minishell, my_minishell->command_line) == 0) {
        handle_alias(my_minishell);
        char **separator = separate_args_spe(my_minishell->command_line, ';');
        if (!separator)
            return;
        for (int i = 0; separator[i] != NULL; i++)
            check_or_and(my_minishell, separator[i]);
        free_my_tab(separator);
    } else {
        if (my_minishell->err == -1)
            my_minishell->end = 1;
    }
}

void set_path_variable(my_minishell_t *my_minishell)
{
    my_env_t *tmp = my_minishell->my_env;

    for (; tmp && my_strcmp(tmp->name, "PATH") != 0; tmp = tmp->next);
    if (tmp) {
        if (my_minishell->last_path != NULL)
            free_my_tab(my_minishell->last_path);
        my_minishell->last_path = copy_tab(tmp->path);
    }

}

void get_arguments(my_minishell_t *my_minishell)
{
    set_path_variable(my_minishell);
    my_minishell->previous_exit = my_minishell->exit;
    handle_my_signals(my_minishell);
    if (isatty(0))
        print_my_prompt(my_minishell);
    if (my_minishell->command_line)
        free(my_minishell->command_line);
    my_minishell->command_line = NULL;
    my_minishell->err = (isatty(0)) ? manage_line_editing(my_minishell) :
    getline(&my_minishell->command_line, &my_minishell->len, stdin);
    if (!isatty(0)) {
        if (my_minishell->err == -1 || !my_minishell->command_line ||
        !my_minishell->command_line[0])
            return;
        my_minishell->command_line[my_strlen(my_minishell->command_line) - 1]
        = '\0';
    }
}

int loop_minishell(my_minishell_t *my_minishell)
{
    int my_return = 0;
    while (my_minishell->end == 0) {
        if (isatty(0))
            enable_raw_mode();
        get_arguments(my_minishell);
        separate_command(my_minishell);
    }
    my_return = (my_minishell->end == 1) ?
    my_minishell->previous_exit : my_minishell->exit;
    return (my_return);
}
