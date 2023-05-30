/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** tools.c
*/

#include "../../include/minishell.h"

int check_for_chars(char *match)
{
    int asterisk = (strchr(match, '*') != NULL);
    int punctuation = (strchr(match, '?') != NULL);
    int hooks1 = (strchr(match, '[') != NULL);
    int hooks2 = (strchr(match, ']') != NULL);

    return (asterisk || punctuation || (hooks1 && hooks2));
}

int get_array_strlen(char **array)
{
    int len = 0;
    int strlen_count = 0;

    for (; array[len] != NULL; len++) {
        strlen_count += strlen(array[len]) + 1;
    }
    return (len);
}

void fill_with_filenames(char *new_argv, glob_t *results)
{
    for (int i = 0; i < results->gl_pathc; i++) {
        new_argv = strcat(new_argv, results->gl_pathv[i]);
        new_argv = strcat(new_argv, " ");
    }
}
