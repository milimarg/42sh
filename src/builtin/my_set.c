/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_set
*/

#include "../../include/minishell.h"

static int handle_error_set(char *cmd)
{
    if (cmd[0] >= '1' && cmd[0] <= '9') {
        write(2, "set: Variable name must begin with a letter.\n", 45);
        return 84;
    }
    for (int i = 0; cmd[i]; i++) {
        if ((cmd[i] >= 0 && cmd[i] <= 47) || (cmd[i] >= 58 && cmd[i] <= 60)
        || (cmd[i] >= 62 && cmd[i] <= 64) || (cmd[i] >= 91 && cmd[i] <= 96)
        || (cmd[i] >= 123 && cmd[i] <= 127)) {
            write(2, "set: Variable name must contain ", 32);
            write(2, "alphanumeric characters.\n", 25);
            return 84;
        }
    }
    return 0;
}

static void display_set(my_minishell_t  *my_minishell, char **all_commands)
{
    variable_t *temp = my_minishell->struct_set;

    for (; temp != NULL; temp = temp->next)
        my_printf("%s\n", temp->string);
}

static char *create_new_str(char **all_commands, char *new_str)
{
    for (int i = 1; all_commands[i]; i++) {
        if (i != 1)
            new_str = my_strcat(new_str, all_commands[i]);
        if (my_strcmp(all_commands[i], "=") != 0 && all_commands[i + 1] != NULL
        && my_strcmp(all_commands[i + 1], "=") != 0)
            new_str = my_strcat(new_str, " ");
    }
    return new_str;
}

int my_set(char **all_commands, my_minishell_t *my_minishell)
{
    char **temp_tab = NULL;
    char *new_str = (all_commands[1] == NULL ? NULL :
    my_strdup(all_commands[1]));
    char **tab = NULL;

    if (all_commands[1] == NULL) {
        display_set(my_minishell, all_commands);
        return (0);
    }
    new_str = create_new_str(all_commands, new_str);
    temp_tab = my_str_to_word_array(new_str);
    for (int i = 0; temp_tab[i]; i++) {
        tab = my_str_to_word_array_spe(temp_tab[i], '=');
        remove_double_set(&my_minishell->struct_set, tab[0]);
        if (handle_error_set(temp_tab[i]) == 84)
            return 1;
        if (add_var(&my_minishell->struct_set, temp_tab[i]) == 84)
            return 1;
    }
    return 0;
}
