/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** check_for_match.c
*/

#include "../../include/minishell.h"

int *check_match(char **argv)
{
    int match_nb = 0;
    int *matches = NULL;
    int match_index = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        if (check_for_chars(argv[i])) {
            match_nb++;
        }
    }
    if (match_nb == 0)
        return (NULL);
    matches = malloc(sizeof(int) * (match_nb + 1));
    for (int i = 0; argv[i] != NULL; i++) {
        if (check_for_chars(argv[i]))
            matches[match_index++] = i;
    }
    matches[match_index] = -1;
    return (matches);
}

int get_match_len(char **argv, int *matches)
{
    int len = 0;

    for (int i = 0; matches[i] != -1; i++) {
        len += strlen(argv[matches[i]]);
    }
    return (len);
}
