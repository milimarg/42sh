/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_double_redirection_from
*/

#include "../../include/minishell.h"

static void set_and_free_values(my_minishell_t *my_minishell, char *command,
char **file, char **redirection)
{
    if (my_minishell->argu)
        free_my_tab(my_minishell->argu);
    my_minishell->argu = separate_args(command);
    free_my_tab(file);
    free_my_tab(redirection);
}

int check_double_redirection_from_two(my_minishell_t *my_minishell,
char **redirection, char *command, char **file)
{
    int fd = open(file[0], O_RDONLY);
    command = my_strdup(redirection[0]);
    for (int i = 1; file[i] != NULL; i++)
        command = my_strcat(command, file[i]);
    while (1) {
        char *tmp = NULL;
        ssize_t n = 0;
        if (isatty(0))
            write(1, "? ", 2);
        int error = getline(&tmp, &n, stdin);
        if (error != -1)
            tmp[(error) - 1] = '\0';
        if (error == -1 || my_strncmp(tmp, file[0], my_strlen(file[0])) == 0)
            break;
    }
    set_and_free_values(my_minishell, command, file, redirection);
    close(fd);
}

int check_double_redirection_from(char *command, my_minishell_t *my_minishell)
{
    int i = 0;
    char **redirection = cut_my_string_by_word(command, "<<");
    while (redirection[i + 1] != NULL)
        i++;
    char **file = separate_args(redirection[i]);
    check_double_redirection_from_two(my_minishell, redirection,
    command, file);
    return (1);
}
