/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_redirection_to
*/

#include "../../include/minishell.h"

int verify_file_existed_redir_to(char const *file)
{
    struct stat path_stat;
    if (stat(file, &path_stat) != 0) {
        return (0);
    }
    if (S_ISREG(path_stat.st_mode) == 1) {
        if (access(file, R_OK) == -1) {
            write(2, file, my_strlen(file));
            write(2, ": Permission denied.\n", 21);
            return (1);
        }
        return (0);
    } else {
        write(2, file, my_strlen(file));
        write(2, ": Is a directory.\n", 18);
        return (2);
    }
}

void check_redirection_to_two(my_minishell_t *my_minishell,
char **redirection, char **file, char *command)
{
    int fd = open(file[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    my_minishell->oldfd = dup(1);
    command = my_strdup(redirection[0]);
    for (int i = 1; file[i] != NULL; i++) {
        command = my_strcat(command, file[i]);
    }
    my_minishell->argu = separate_args(command);
    free_my_tab(redirection);
    free_my_tab(file);
    dup2(fd, 1);
    close(fd);
}

int check_redirection_to(char *command, my_minishell_t *my_minishell)
{
    int i = 0;
    char **redirection = separate_args_spe(command, '>');
    while (redirection[i + 1] != NULL)
        i++;
    char **file = separate_args(redirection[i]);
    int check = verify_file_existed_redir_to(file[0]);
    if (check != 0) {
        free_my_tab(redirection);
        free_my_tab(file);
        my_minishell->exit = 1;
        return (-1);
    } else {
        check_redirection_to_two(my_minishell, redirection, file, command);
        return (1);
    }
}
