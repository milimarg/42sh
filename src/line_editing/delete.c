/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** delete
*/

#include "../../include/minishell.h"

int handle_delete(line_t *struct_line)
{
    if (struct_line->buffer != 127 && struct_line->buffer != '\b')
        return (0);
    if (struct_line->index > 0) {
        struct_line->index--;
        struct_line->len--;
        for (int i = struct_line->index; i < struct_line->len; i++)
            struct_line->string[i] = struct_line->string[i + 1];
        struct_line->string[struct_line->len] = '\0';
        write(1, "\033[D", 3);
        write(1, "\033[P", 3);
        for (int i = struct_line->index; i < struct_line->len; i++)
            write(1, &struct_line->string[i], 1);
        for (int i = struct_line->len; i > struct_line->index; i--)
            write(1, "\033[D", 3);
    }
    return (1);
}
