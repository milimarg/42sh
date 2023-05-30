/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** write_char
*/

#include "../../include/minishell.h"

int handle_char(line_t *struct_line)
{
    if (struct_line->buffer < 32 || struct_line->buffer > 126)
        return (0);
    if (struct_line->len < 1024 - 1) {
        struct_line->len++;
        for (int i = struct_line->len - 1; i > struct_line->index; i--)
            struct_line->string[i] = struct_line->string[i - 1];
        struct_line->string[struct_line->index] = struct_line->buffer;
        struct_line->index++;
        write(1, &struct_line->buffer, 1);
        for (int i = struct_line->index; i < struct_line->len; i++)
            write(1, &struct_line->string[i], 1);
        for (int i = struct_line->len; i > struct_line->index; i--)
            write(1, "\033[D", 3);
    }
    return (1);
}
