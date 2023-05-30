/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_echo
*/

#include "../../include/minishell.h"

static const char ECHO_CHAR_RES[] = {
    '\a',
    '\b',
    '\t',
    '\n',
    '\v',
    '\f',
    '\r',
    '\'',
    '\"',
    '\\'
};

static const char ECHO_CHAR[] = {
    'a',
    'b',
    't',
    'n',
    'v',
    'f',
    'r',
    '\'',
    '\"',
    '\\'
};

int check_after_backslash(char *my_text, int i)
{
    if (my_text[i + 1] == '\0')
        return (1);
    for (int a = 0; a < 10; a++) {
        if (my_text[i + 1] == ECHO_CHAR[a]) {
            write(1, &ECHO_CHAR_RES[a], 1);
            return (0);
        }
    }
    return (1);
}

int my_echo_print_char(char *my_text, int i)
{
    if (my_text[i] == '\\') {
        if (!check_after_backslash(my_text, i)) {
            return (i + 1);
        } else {
            write(1, "\\", 1);
            return (i);
        }
    } else {
        write(1, &my_text[i], 1);
        return (i);
    }
}

void my_echo_print(char *text)
{
    for (int i = 0; text[i] != '\0'; i++) {
        i = my_echo_print_char(text, i);
    }
    return;
}

int my_echo(char **all_command, my_minishell_t *my_minishell)
{
    int i = 1;

    if (all_command[i] == NULL) {
        write(1 , "\n", 1);
        return (0);
    } else {
        for (; all_command[i] != NULL; i++) {
            my_echo_print(all_command[i]);
            (all_command[i + 1] != NULL) ? write(1, " ", 1) : 0;
        }
        write(1 , "\n", 1);
    }
    return (0);
}
