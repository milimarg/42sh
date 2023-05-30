/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** initialize_pwd
*/

#include "../../include/minishell.h"

static void init_pwd_home(my_minishell_t *my_minishell)
{
    my_env_t *home = my_minishell->my_env;
    for (; home != NULL && my_strcmp(home->name, "HOME") != 0;
        home = home->next);
    if (home != NULL) {
        if (my_minishell->pos->home != NULL)
            free(my_minishell->pos->home);
        my_minishell->pos->home = home->path[0];
    } else {
        if (my_minishell->pos->home != NULL)
            free(my_minishell->pos->home);
        my_minishell->pos->home = NULL;
    }
}

static void init_pwd_path(my_minishell_t *my_minishell)
{
    my_env_t *path = my_minishell->my_env;
    for (; path != NULL && my_strcmp(path->name, "PATH") != 0;
        path = path->next);
    if (path != NULL) {
        if (my_minishell->pos->path != NULL)
            free(my_minishell->pos->path);
        my_minishell->pos->path = path->path;
    } else {
        if (my_minishell->pos->path != NULL)
            free(my_minishell->pos->path);
        my_minishell->pos->path = NULL;
    }
}

void initialize_pwd(my_minishell_t *my_minishell)
{
    my_minishell->pos->pwd = getcwd(NULL, 0);
    my_env_t *oldpwd = my_minishell->my_env;
    for (;oldpwd != NULL && my_strcmp(oldpwd->name, "OLDPWD") != 0;
        oldpwd = oldpwd->next);
    my_minishell->pos->oldpwd = NULL;
    init_pwd_home(my_minishell);
    init_pwd_path(my_minishell);
}
