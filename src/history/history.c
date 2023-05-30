/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** history
*/

#include "../../include/minishell.h"

void add_history_elem(line_t *struct_line)
{
    history_t *new_node = malloc(sizeof(history_t));

    memset(new_node->string, '\0', 1024);
    strcpy(new_node->string, struct_line->string);
    new_node->len = struct_line->len;
    if (struct_line->history_head != NULL)
        struct_line->history_head->prev = new_node;
    new_node->prev = NULL;
    new_node->next = struct_line->history_head;
    struct_line->history_head = new_node;
    struct_line->current_history = struct_line->history_head;
}

void retrieve_history_elem(line_t *struct_line)
{
    memset(struct_line->string, '\0', 1024);
    for (; struct_line->index != struct_line->len; struct_line->index++)
        write(1, "\033[C", 3);
    for (int i = 0; i < struct_line->len; i++) {
        write(1, "\033[D", 3);
        write(1, "\033[P", 3);
    }
    if (struct_line->current_history != NULL) {
        strcpy(struct_line->string, struct_line->current_history->string);
        struct_line->index = struct_line->current_history->len;
        struct_line->len = struct_line->current_history->len;
        struct_line->buffer = '\0';
    } else {
        struct_line->index = 0;
        struct_line->len = 0;
        struct_line->buffer = '\0';
    }
    for (int i = 0; i < struct_line->len; i++)
        write(1, &struct_line->string[i], 1);
}
