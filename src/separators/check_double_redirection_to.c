/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_double_redirection_to
*/

#include "../../include/minishell.h"

void check_double_redirection_to_two(my_minishell_t *my_minishell,
char **redirection, char **file, char *command)
{
    int fd = open(file[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
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

int check_double_redirection_to(char *command, my_minishell_t *my_minishell)
{
    int i = 0;
    char **redirection = cut_my_string_by_word(command, ">>");

    while (redirection[i + 1] != NULL)
        i++;
    char **file = separate_args(redirection[i]);
    int check = verify_file_existed_redir_to(file[0]);
    if (check == 1) {
        free_my_tab(redirection);
        return (-1);
    } else {
        check_double_redirection_to_two(my_minishell, redirection, file,
        command);
        return (1);
    }
}
