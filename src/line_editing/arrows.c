/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** arrows
*/

#include "../../include/minishell.h"

void retrieve_history_elem(line_t *struct_line);

static void arrow_right(line_t *struct_line, char temp_arrow[3])
{
    if (temp_arrow[1] == 'D' && struct_line->index <= struct_line->len) {
        if (struct_line->index > 0) {
            struct_line->index--;
            write(1, "\033[D", 3);
        }
    }
}

static void arrow_left(line_t *struct_line, char temp_arrow[3])
{
    if (temp_arrow[1] == 'C' && struct_line->index <= struct_line->len) {
        if (struct_line->index < struct_line->len) {
            struct_line->index++;
            write(1, "\033[C", 3);
        }
    }
}

static void arrow_up(line_t *struct_line, char temp_arrow[3])
{
    if (temp_arrow[1] == 'A') {
        if (struct_line->current_history != NULL) {
            struct_line->current_history
            = (struct_line->current_history->next != NULL) ?
            struct_line->current_history->next
            : struct_line->current_history;
            retrieve_history_elem(struct_line);
        } else {
            struct_line->current_history = struct_line->history_head;
            retrieve_history_elem(struct_line);
        }
    }
}

static void arrow_down(line_t *struct_line, char temp_arrow[3])
{
    if (temp_arrow[1] == 'B') {
        if (struct_line->current_history != NULL) {
            struct_line->current_history = struct_line->current_history->prev;
            retrieve_history_elem(struct_line);
        }
    }
}

int handle_arrows(line_t *struct_line)
{
    char temp_arrow[3] = {0};

    if (struct_line->buffer == '\x1b') {
        if (read(1, &temp_arrow[0], 1) != 1)
            return (1);
        if (read(1, &temp_arrow[1], 1) != 1)
            return (1);
        if (temp_arrow[0] == '[') {
            arrow_right(struct_line, temp_arrow);
            arrow_left(struct_line, temp_arrow);
            arrow_up(struct_line, temp_arrow);
            arrow_down(struct_line, temp_arrow);
        }
        return (1);
    }
    return (0);
}
