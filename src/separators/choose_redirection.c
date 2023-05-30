/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-noe.tritsch
** File description:
** choose_redirection
*/

#include "../../include/minishell.h"

void choose_redirection(my_minishell_t *my_minishell, char *command)
{
    int double_error = check_double_redirection(command, my_minishell, 0);
    if (double_error == 0) {
        int error = check_redirection(command, my_minishell, 0);
        if (error == 0)
            my_minishell->argu = separate_args(command);
        if (error != -1) {
            minishell_ope(my_minishell, command);
        }
        if (error == 1)
            dup2(my_minishell->oldfd, 1);
        if (error == 2)
            dup2(my_minishell->oldfd, 0);
    }
    if (double_error == 1) {
        minishell_ope(my_minishell, command);
        dup2(my_minishell->oldfd, 1);
    }
}
