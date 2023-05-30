/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** minishell_ope
*/

#include "../include/minishell.h"

void check_errno(char *command)
{
    if (errno == ENOEXEC) {
        write(2, command, my_strlen(command));
        write(2, ": Exec format error. Wrong Architecture.\n", 41);
        exit(1);
    }
}

int my_command_minishell(my_minishell_t *my_minishell)
{
    char **all_command = my_minishell->argu;
    int return_value = 0;
    for (int i = 0; BUILTIN_TAB[i]; i++)
        if (my_strncmp(all_command[0], BUILTIN_TAB[i], BUILTIN_SIZE[i]) == 0) {
            return_value = BUILTIN_POINTERS[i](all_command, my_minishell);
            return (return_value);
        }
    return (-1);
}

void remove_quote(char **argu)
{
    int lenght = 0;

    for (int i = 0; argu && argu[i] != NULL; i++) {
        lenght = my_strlen(argu[i]);
        if (argu[i][0] == '\'' || argu[i][0] == '\"' && lenght > 2) {
            argu[i][lenght - 1] = '\0';
            argu[i]++;
            char *tmp = my_strdup(argu[i]);
            argu[i]--;
            free(argu[i]);
            argu[i] = tmp;
        }
        if (argu[i][0] == '\'' || argu[i][0] == '\"' && lenght == 2) {
            argu[i][lenght - 1] = '\0';
            argu[i][0] = '\0';
        }
    }
}

void execute_command(my_minishell_t *my_minishell)
{
    char **env_tmp = tab_env_from_queue(my_minishell->my_env);
    execve(my_minishell->argu[0], my_minishell->argu, env_tmp);
    check_errno(my_minishell->argu[0]);
    if (my_minishell->last_path) {
        for (int i = 0 ; my_minishell->last_path[i] != NULL; i++) {
            char *tmp = my_strcat_minishell(my_minishell->last_path[i],
            my_minishell->argu[0]);
            execve(tmp, my_minishell->argu, env_tmp);
            check_errno(tmp);
            free(tmp);
        }
    }
    command_not_found(my_minishell, my_minishell->argu[0], env_tmp);
}

void minishell_ope(my_minishell_t *my_minishell, char *command)
{
    for (int i = 0; my_minishell->argu[i]; i++) {
        if (replace_variables(my_minishell, i) == 84)
            return;
    }
    remove_quote(my_minishell->argu);
    int res = my_command_minishell(my_minishell);
    int child = 1;

    if (res == -1)
        child = fork();
    if (child == 0 && res == -1) {
        execute_command(my_minishell);
    } else if (child != 0) {
        my_minishell->last_pid = child;
        waitpid(child, &my_minishell->error, 0);
        switch_my_exit(my_minishell);
    }
    (res != -1) ? my_minishell->exit = res : my_minishell->exit;
}
