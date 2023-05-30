/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** split_my_command_line
*/

#include "../../include/minishell.h"

char **split_my_command_line(char *command_line, char symb)
{
    char **separator = my_str_to_word_array_spe(command_line, ' ');
    char *tmp = my_strdup(separator[0]);

    for (int i = 1; separator[i] != NULL; i++) {
        tmp = my_strcat(tmp, " ");
        tmp = my_strcat(tmp, separator[i]);
    }
    free_my_tab(separator);
    separator = my_str_to_word_array_spe(tmp, symb);
    for (int i = 0; separator[i] != NULL; i++) {
        separator[i] = str_clean(separator[i]);
    }
    free(tmp);
    return (separator);
}
