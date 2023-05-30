/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** write_end
*/

#include "../../include/minishell.h"

void add_history_elem(line_t *struct_line);

int handle_next_line(line_t *struct_line, my_minishell_t *my_minishell)
{
    if (struct_line->buffer == '\n') {
        if (struct_line->len > 0)
            add_history_elem(struct_line);
        struct_line->string[struct_line->len] = '\0';
        if (my_minishell->command_line)
            free(my_minishell->command_line);
        my_minishell->command_line = strdup(struct_line->string);
        for (int i = 0; struct_line->len; struct_line->len--)
            struct_line->string[struct_line->len - 1] = '\0';
        struct_line->index = 0;
        write(1, "\n", 1);
        struct_line->current_history = NULL;
        return (1);
    }
    return (0);
}
