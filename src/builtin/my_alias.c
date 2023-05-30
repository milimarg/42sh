/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** alias_function
*/

#include "../../include/minishell.h"

int my_alias(char **all_commands, my_minishell_t *my_minishell)
{
    int res = check_alias_str(my_minishell->command_line, all_commands);

    if (res == 84)
        return (1);
    if (all_commands[1] == NULL) {
        display_alias(my_minishell, all_commands);
        return (0);
    }
    if (all_commands[2] == NULL)
        return (0);
    if (my_strcmp(all_commands[1], "alias") == 0) {
        write(2, "alias: Too dangerous to alias that.\n", 36);
        return (1);
    }
    remove_double(&my_minishell->struct_alias, all_commands[1]);
    if (res == 1)
        add_node(&my_minishell->struct_alias,
        my_minishell->command_line, all_commands);
    return (0);
}

static int go_to_next_command(char **all_commands, int i)
{
    for (; all_commands[i] && my_strcmp(all_commands[i], "|") != 0
    && my_strcmp(all_commands[i], "||") != 0
    && my_strcmp(all_commands[i], ";") != 0
    && my_strcmp(all_commands[i], "&&") != 0; i++);
    return (i);
}

static void change_command_line(char **temp_command_line, char **all_commands)
{
    (*temp_command_line) = my_strdup(all_commands[0]);
    if (all_commands[1])
        (*temp_command_line) = my_strcat((*temp_command_line), " ");
    for (int i = 1; all_commands[i]; i++) {
        (*temp_command_line) = my_strcat((*temp_command_line), all_commands[i]);
        if (all_commands[i + 1])
            (*temp_command_line) = my_strcat((*temp_command_line), " ");
    }
}

static char **handle_alias_two(char **all_commands, alias_t *temp, int i,
int *is_aliased)
{
    if (my_strcmp(temp->name, all_commands[i]) == 0) {
        free(all_commands[i]);
        all_commands[i] = temp->command;
        *is_aliased = 1;
    }
    return (all_commands);
}

void handle_alias(my_minishell_t *my_minishell)
{
    char **all_commands = separate_args(my_minishell->command_line);
    char *temp_command_line = NULL;
    int is_aliased = 0;

    for (int i = 0; all_commands[i]; i++) {
        if (is_builtin(all_commands[i]))
            i = go_to_next_command(all_commands, i);
        if (!all_commands[i])
            break;
        for (alias_t *temp = my_minishell->struct_alias; temp != NULL;
        temp = temp->next)
            all_commands = handle_alias_two(all_commands, temp, i, &is_aliased);
    }
    change_command_line(&temp_command_line, all_commands);
    free(my_minishell->command_line);
    my_minishell->command_line = temp_command_line;
    if (is_aliased)
        handle_alias(my_minishell);
}
