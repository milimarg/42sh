/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** globbing.c
*/

#include "../../include/minishell.h"

static int get_files_strlen(char **argv, int *matches, int *strlen_total)
{
    glob_t results = {0};
    int i = 0;

    if (matches == NULL)
        return (0);
    for (int j = 0; matches[j] != -1; j++) {
        if (glob(argv[matches[j]], 0, NULL, &results) != 0)
            return (0);
        for (i = 0; i < results.gl_pathc; i++) {
            *strlen_total += strlen(results.gl_pathv[i]) + 1;
        }
        globfree(&results);
    }
    return (i);
}

static char *get_command_name(char *command)
{
    int len = 0;

    for (; command[len] != ' ' && command[len] != '\0'; len++);
    return (strndup(command, len));
}

static void display_error(char *command)
{
    char *command_name = get_command_name(command);

    write(2, command_name, strlen(command_name));
    write(2, ": No match.\n", 12);
    free(command_name);
}

static char *get_globbing_infos(char **argv, int *matches, char *command,
int strlen_total_and_files_nb[2])
{
    int strlen_total = strlen_total_and_files_nb[0];
    int files_nb = strlen_total_and_files_nb[1];
    int match_len = get_match_len(argv, matches);
    int total_len = strlen(command) - match_len + strlen_total;
    char *new_argv = malloc(sizeof(char) * (total_len + 1));

    fill_new_argv(argv, files_nb, new_argv, matches);
    new_argv[total_len] = 0;
    return (new_argv);
}

char *run_globbings(char *command)
{
    char *new_argv = NULL;
    char **argv = my_str_to_word_array_spe(command, ' ');
    int *matches = check_match(argv);
    int strlen_total = 0;
    int files_nb = get_files_strlen(argv, matches, &strlen_total);

    if (files_nb == 0) {
        if (matches != NULL) {
            display_error(command);
            free_globbings(argv, matches);
            return (NULL);
        } else {
            free_globbings(argv, matches);
            return (strdup(command));
        }
    }
    new_argv = get_globbing_infos(argv, matches, command,
    (int[2]){strlen_total, files_nb});
    free_globbings(argv, matches);
    return (new_argv);
}
