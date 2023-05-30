/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** command_not_found
*/

#include "../../include/minishell.h"

void command_not_found(my_minishell_t *min, char *command, char **my_env)
{
    free_my_tab(my_env);
    struct stat path_stat;
    write(2, command, my_strlen(command));
    if (stat(command, &path_stat) == 0 && S_ISDIR(path_stat.st_mode) == 1) {
        write(2, ": Permission denied.\n", 21);
    } else {
        write(2, ": Command not found.\n", 21);
    }
    min->end = 1;
    min->exit = 1;
    min->previous_exit = 1;
    exit(1);
}
