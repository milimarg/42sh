/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-bsminishell2-augustin.grosnon
** File description:
** check_and_replace_env_loop
*/

#include "../../include/minishell.h"

static int check_and_replace_env_loop_ext_two(my_minishell_t *min, int i)
{
    char *found_env = NULL;
    char *found_local = NULL;

    if (min->argu[i][0] == '$') {
        if (min->argu[i][1] == '\0')
            return (0);
        min->argu[i]++;
        found_local = find_in_local_var(min->argu[i], min);
        found_env = find_in_env(min->argu[i], min);
        if (found_env == NULL && found_local == NULL) {
            write(2, min->argu[i], my_strlen(min->argu[i]));
            write(2, ": Undefined variable.\n", 22);
            min->exit = 1;
            return (84);
        }
        min->argu[i] = (found_env) ? found_env : min->argu[i];
        min->argu[i] = (found_local) ? found_local : min->argu[i];
    }
    return (0);
}

static int check_replace_spec_two(my_minishell_t *min, char *str, int i)
{
    if (min->argu[i][0] == '$' && min->argu[i][1] == '!') {
        str = malloc(sizeof(char) * (20));
        for (int i = 0; i < 20; i++)
            str[i] = '\0';
        convert_nbr_to_string(min->last_pid, str, min);
        min->dollar_index = 0;
        min->argu[i] = str;
        return (1);
    }
    if (min->argu[i][0] == '$' && min->argu[i][1] == '$') {
        str = malloc(sizeof(char) * (20));
        for (int i = 0; i < 20; i++)
            str[i] = '\0';
        convert_nbr_to_string(getpid(), str, min);
        min->dollar_index = 0;
        min->argu[i] = str;
        return (1);
    }
    return (0);
}

static int check_replace_spec_one(my_minishell_t *min, char *str, int i)
{
    if (min->argu[i][0] == '$' && min->argu[i][1] == '?') {
        str = malloc(sizeof(char) * (4));
        for (int i = 0; i < 4; i++)
            str[i] = '\0';
        convert_nbr_to_string(min->exit, str, min);
        min->dollar_index = 0;
        min->argu[i] = str;
        return (1);
    }
    return (0);
}

static int check_and_replace_env_loop_ext_one(my_minishell_t *min, int i)
{
    char *str = NULL;

    if (my_strlen(min->argu[i]) == 2) {
        if (check_replace_spec_one(min, str, i) == 1)
            return (1);
        if (check_replace_spec_two(min, str, i) == 1)
            return (1);
    }
    return (0);
}

int replace_variables(my_minishell_t *min, int i)
{
    int error = check_and_replace_env_loop_ext_one(min, i);

    if (error == 0)
        error = check_and_replace_env_loop_ext_two(min, i);
    return (error);
}
