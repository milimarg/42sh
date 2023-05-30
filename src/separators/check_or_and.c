/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** check_or_and
*/

#include "../../include/minishell.h"

void get_order_or_and_two(char *str, int i, int idx, int *order)
{
    if (strcmp_word(str, i, "&&")) {
        order[idx] = 0;
    }
    if (strcmp_word(str, i, "||")) {
        order[idx] = 1;
    }
}

int *get_order_or_and(char *str, int presence)
{
    int *order = malloc(sizeof(int) * presence);
    int idx = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        for (; quote_check(str, i) != 0; i++);
        i = (str[i] == '\0') ? i - 1 : i;
        if (strcmp_word(str, i, "&&") || strcmp_word(str, i, "||")) {
            get_order_or_and_two(str, i, idx, order);
            i = (str[i + 2] == ' ' || str[i + 2] == '\t') ?
            ignore_space_and_tabs(i + 2, str) : i + 1;
            idx++;
        }
    }
    return (order);
}

static int check_return_order(int *command_return, int order, char *cut_str,
my_minishell_t *my_minishell)
{
    char *new_globbing = NULL;

    if ((*command_return == 0 && order == 0) ||
        (*command_return != 0 && order == 1)) {
        new_globbing = run_globbings(cut_str);
        if (new_globbing == NULL)
            return (1);
        handle_pipe(my_minishell, new_globbing);
        *command_return = my_minishell->exit;
        free(new_globbing);
    }
    return (0);
}

void check_or_and(my_minishell_t *my_minishell, char *command)
{
    int nbr = 0;
    char **cut_string = NULL;
    int *order = {0};
    int command_return = 0;
    char *new_globbing = NULL;

    cut_string = cut_my_string_by_two_word(command, (char *[2]) {"&&", "||"});
    for (; cut_string[nbr + 1] != NULL; nbr++);
    order = get_order_or_and(command, nbr);
    new_globbing = run_globbings(cut_string[0]);
    if (new_globbing == NULL)
        return;
    handle_pipe(my_minishell, new_globbing);
    free(new_globbing);
    command_return = my_minishell->exit;
    for (int i = 1; cut_string[i] != NULL; i++) {
        if (check_return_order(&command_return, order[i - 1], cut_string[i],
        my_minishell))
            continue;
    }
}
