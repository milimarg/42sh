/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.tritsch
** File description:
** handle_pipe
*/

#include "../../include/minishell.h"

void handle_pipe_two(my_minishell_t *my_minishell, char **all_command)
{
    if (all_command[2] != NULL)
        return;
    int pipefd[2];
    pipe(pipefd);
    int child = fork();
    if (child == 0) {
        close(pipefd[0]);
        dup2(pipefd[1], 1);
        choose_redirection(my_minishell, all_command[0]);
        dup2(my_minishell->dup_one, 1);
        exit(0);
    } else {
        for (int i = 0;  i < 100000; i++);
        close(pipefd[1]);
        dup2(pipefd[0], 0);
        choose_redirection(my_minishell, all_command[1]);
        dup2(my_minishell->dup_zero, 0);
    }
}

void handle_pipe(my_minishell_t *my_minishell, char *command)
{
    char **pipe_separator = separate_args_spe(command,'|');

    if (pipe_separator[1] == NULL) {
        int *symb = count_symb(command);
        if (symb[124] == 0)
            choose_redirection(my_minishell, pipe_separator[0]);
        else {
            write(2, "Invalid null command.\n", 22);
            my_minishell->exit = 1;
        }
        free(symb);
        free_my_tab(pipe_separator);
        return;
    }
    handle_pipe_two(my_minishell, pipe_separator);
    dup2(my_minishell->dup_one, 1);
    free_my_tab(pipe_separator);
    return;
}
