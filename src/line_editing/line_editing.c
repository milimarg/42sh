/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** ex03.c
*/

#include "../../include/minishell.h"

int handle_arrows_ctrl(line_t *struct_line);
int handle_arrows(line_t *struct_line);
int handle_next_line(line_t *struct_line, my_minishell_t *my_minishell);
int handle_char(line_t *struct_line);
int handle_delete(line_t *struct_line);
int check_eof(line_t *struct_line, my_minishell_t *my_minishell);
int handle_tab(line_t *struct_line, my_minishell_t *my_minishell);

int manage_line_editing(my_minishell_t *my_minishell)
{
    line_t *struct_line = my_minishell->struct_line;

    while (1) {
        read(1, &struct_line->buffer, 1);
        if (check_eof(struct_line, my_minishell))
            return (1);
        if (handle_arrows(struct_line))
            continue;
        if (handle_arrows_ctrl(struct_line))
            continue;
        if (handle_tab(struct_line, my_minishell))
            continue;
        if (handle_delete(struct_line))
            continue;
        if (handle_char(struct_line))
            continue;
        if (handle_next_line(struct_line, my_minishell))
            return (0);
    }
    return 0;
}
