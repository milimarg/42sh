/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** check_redirection_from
*/

#include "../../include/minishell.h"

int verify_file_existed_redir_from(char const *file)
{
    struct stat path_stat;
    if (stat(file, &path_stat) != 0) {
        write(2, file, my_strlen(file));
        write(2, ": No such file or directory.\n", 29);
        return (2);
    }
    if (S_ISREG(path_stat.st_mode) == 1) {
        if (access(file, R_OK) == -1) {
            write(2, file, my_strlen(file));
            write(2, ": Permission denied.\n", 21);
            return (1);
        }
        return (0);
    } else {
        return (0);
    }
}

void check_redirection_from_two(my_minishell_t *my_minishell,
char **redirection, char *command, char **file)
{
    int fd = open(file[0], O_RDONLY);
    my_minishell->oldfd = dup(0);
    command = my_strdup(redirection[0]);
    for (int i = 1; file[i] != NULL; i++) {
        command = my_strcat(command, file[i]);
    }
    my_minishell->argu = separate_args(command);
    dup2(fd, 0);
    close(fd);
}

int check_redirection_from(char *command, my_minishell_t *my_minishell)
{
    int i = 0;
    char **redirection = separate_args_spe(command, '<');
    while (redirection[i + 1] != NULL)
        i++;
    char **file = separate_args(redirection[i]);
    int check = verify_file_existed_redir_from(file[0]);
    if (check != 0) {
        my_minishell->exit = 1;
        free_my_tab(redirection);
        free_my_tab(file);
        return (-1);
    } else {
        check_redirection_from_two(my_minishell, redirection, command, file);
        free_my_tab(redirection);
        free_my_tab(file);
        return (2);
    }
}
