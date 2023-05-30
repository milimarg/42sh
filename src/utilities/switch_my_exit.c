/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** switch_my_exit
*/

#include "../../include/minishell.h"

void switch_my_exit(my_minishell_t *my_minishell)
{
    if (my_minishell->end == 1)
        return;
    if (WIFEXITED(my_minishell->error)) {
        my_minishell->exit = WEXITSTATUS(my_minishell->error);
        return;
    }
    if (WIFSIGNALED(my_minishell->error)) {
        my_minishell->exit = WTERMSIG(my_minishell->error) + 128;
        if (my_minishell->exit == 139)
            write(2, "Segmentation fault", 18);
        if (my_minishell->exit == 136)
            write(2, "Floating exception", 18);
        if (WCOREDUMP(my_minishell->error))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
        return;
    }
}
