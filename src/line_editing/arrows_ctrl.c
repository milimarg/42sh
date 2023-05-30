/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** arrow_ctrl
*/

#include "../../include/minishell.h"

static void arrow_right(line_t *struct_line, char temp_arrow[3])
{
    if (temp_arrow[1] == 'D' && struct_line->index
    <= struct_line->len && struct_line->index > 0) {
        for (; struct_line->string[struct_line->index - 1]
        == ' '; struct_line->index--)
            write(1, "\033[D", 3);
        for (; struct_line->string[struct_line->index - 1]
        && struct_line->string[struct_line->index - 1]
        != ' '; struct_line->index--)
            write(1, "\033[D", 3);
    }
}

static void arrow_left(line_t *struct_line, char temp_arrow[3])
{
    if (temp_arrow[1] == 'C' && struct_line->index
    <= struct_line->len && struct_line->index < struct_line->len) {
        for (; struct_line->string[struct_line->index]
        == ' '; struct_line->index++)
            write(1, "\033[C", 3);
        for (; struct_line->string[struct_line->index]
        && struct_line->string[struct_line->index]
        != ' '; struct_line->index++)
            write(1, "\033[C", 3);
    }
}

static int reset_term_block_and_return(int flags, int return_value)
{
    flags &= ~O_NONBLOCK;
    fcntl(0, F_SETFL, flags);
    return (return_value);
}

int handle_arrows_ctrl(line_t *struct_line)
{
    char temp_arrow[3] = {0};
    int flags = 0;

    if (struct_line->buffer == ';') {
        flags = fcntl(0, F_GETFL, 0);
        flags |= O_NONBLOCK;
        fcntl(0, F_SETFL, flags);
        if (read(1, &temp_arrow[0], 1) != 1)
            return (reset_term_block_and_return(flags, 0));
        if (read(1, &temp_arrow[1], 1) != 1)
            return (reset_term_block_and_return(flags, 0));
        if (temp_arrow[0] == '5') {
            arrow_right(struct_line, temp_arrow);
            arrow_left(struct_line, temp_arrow);
        }
        return (reset_term_block_and_return(flags, 1));
    }
    return (0);
}
