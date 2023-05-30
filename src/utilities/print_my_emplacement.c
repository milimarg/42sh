/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** print_my_emplacement
*/

#include "../../include/minishell.h"

void print_my_file(char *path)
{
    int last_slash = 0;
    for (int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '/')
            last_slash = i;
    }
    for (int j = last_slash + 1; path[j] != '\0'; j++) {
        my_printf("%c", path[j]);
    }
}

void print_my_prompt(my_minishell_t* my_minishell)
{
    my_env_t *username = my_minishell->my_env;
    my_env_t *pwd = my_minishell->my_env;
    while (username != NULL && my_strcmp(username->name, "USER") != 0)
        username = username->next;
    my_printf("[%d]:" , my_minishell->exit);
    if (username != NULL)
        my_printf("[\033[34;01m%s\033[00m]:", username->path[0]);
    if (my_minishell->pos->pwd != NULL) {
        my_printf("[\033[31;01m");
        print_my_file(my_minishell->pos->pwd);
        my_printf("\033[00m]");
    }
    my_printf("> ");
}
