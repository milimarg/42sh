/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** end_of_file
*/

#include "../../include/minishell.h"

int check_eof(line_t *struct_line, my_minishell_t *my_minishell)
{
    if (struct_line->buffer == 4) {
        my_minishell->end = -1;
        if (isatty(0))
            write(2, "exit\n", 5);
        return (1);
    }
    return (0);
}
