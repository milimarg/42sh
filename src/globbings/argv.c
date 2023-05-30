/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** argv.c
*/

#include "../../include/minishell.h"

static int fill_filenames_for_argv(int *matches, char **argv, char *new_argv,
int i)
{
    int run_match = 0;
    glob_t results = {0};

    for (int j = 0; matches[j] != -1; j++) {
        if (i != matches[j])
            continue;
        run_match = 1;
        glob(argv[matches[j]], 0, NULL, &results);
        fill_with_filenames(new_argv, &results);
        globfree(&results);
        matches[j] = -2;
    }
    return (run_match);
}

void fill_new_argv(char **argv, int files_nb, char *new_argv, int *matches)
{
    glob_t results = {0};
    int run_match = 0;

    new_argv[0] = 0;
    for (int i = 0; argv[i] != NULL; i++) {
        run_match = fill_filenames_for_argv(matches, argv, new_argv, i);
        if (!run_match) {
            new_argv = strcat(new_argv, argv[i]);
            new_argv = strcat(new_argv, " ");
        }
    }
}
