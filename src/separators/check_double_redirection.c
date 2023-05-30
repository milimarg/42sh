/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_double_redirection
*/

#include "../../include/minishell.h"

int check_double_redirection_three(char *command, my_minishell_t *my_minishell)
{
    for (int i = 0; command[i] != '\0'; i++) {
        if (strcmp_word(command, i, ">>")) {
            return (check_double_redirection_to(command, my_minishell));
        }
        if (strcmp_word(command, i, "<<")) {
            return (check_double_redirection_from(command, my_minishell));
        }
        for (; quote_check(command, i) != 0 && command[i + 1] != '\0'; i++);
    }
}

int check_double_redirection_two(char *command, my_minishell_t *my_minishell,
int redir, int stat)
{
    if (stat == 1) {
        write(2, "Missing name for redirect.\n", 27);
        my_minishell->exit = 1;
        return (-1);
    }
    if (redir > 1) {
        write(2, "Ambiguous output redirect.\n", 27);
        my_minishell->exit = 1;
        return (-1);
    }
    if (redir == 1)
        return (check_double_redirection_three(command, my_minishell));
    else
        return (0);
}

int check_double_redirection(char *command, my_minishell_t *my_minishell,
int redir)
{
    int stat = 0;
    for (int i = 0; command[i] != '\0' ; i++) {
        if (stat == 1 && strcmp_word(command, i, ">>") ||
            stat == 1 && strcmp_word(command, i, "<<")) {
            write(2, "Missing name for redirect.\n", 27);
            my_minishell->exit = 1;
            return (-1);
        }
        if (strcmp_word(command, i, ">>") ||
            strcmp_word(command, i, "<<")) {
            redir++;
            i += 2;
            i = ignore_space_and_tabs(i, command);
            stat = 1;
        } else
            stat = 0;
        for (; quote_check(command, i) != 0 && command[i + 1] != '\0'; i++);
    }
    return (check_double_redirection_two(command, my_minishell, redir, stat));
}
