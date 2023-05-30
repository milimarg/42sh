/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_cd_two
*/

#include "../../include/minishell.h"

int path_to_home(my_minishell_t *my_minishell)
{
    if (my_minishell->pos->home != NULL) {
        my_minishell->pos->oldpwd = my_minishell->pos->pwd;
        my_minishell->pos->pwd = my_minishell->pos->home;
        chdir(my_minishell->pos->pwd);
    }
    return (0);
}

int path_to_previous(my_minishell_t *my_minishell)
{
    if (my_minishell->pos->oldpwd != NULL) {
        char *tmp = my_minishell->pos->pwd;
        my_minishell->pos->pwd = my_minishell->pos->oldpwd;
        my_minishell->pos->oldpwd = tmp;
        chdir(my_minishell->pos->pwd);
        return (0);
    } else {
        write(2 , ": No such file or directory.\n", 29);
        return (1);
    }
}

char **back_from_path(char *str)
{
    char **tmp = malloc(sizeof(char *) * 2);
    int last_slash = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/')
            last_slash = i;
    }
    tmp[0] = malloc(sizeof(char) * (last_slash + 2));
    int j = 0;
    while (j != last_slash) {
        tmp[0][j] = str[j];
        j++;
    }
    tmp[0][j] = '\0';
    tmp[1] = NULL;
    return (tmp);
}

int path_to_back(my_minishell_t *my_minishell)
{
    char **tmp = back_from_path(my_minishell->pos->pwd);
    my_minishell->pos->oldpwd = my_minishell->pos->pwd;
    my_minishell->pos->pwd = tmp[0];
    chdir(my_minishell->pos->pwd);
    return (0);
}
