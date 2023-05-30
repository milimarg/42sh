/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_repeat
*/

#include "../../include/minishell.h"

static char *rebuild_command_line(char **tab)
{
    char *command_line = my_strdup(tab[0]);

    if (!tab[1])
        return (command_line);
    for (int i = 1; tab[i]; i++)
        command_line =
        my_strcat(command_line, my_strcat(my_strdup(" "), tab[i]));
    return (command_line);
}

static int handle_error(int nb_arg, char *arg_number)
{
    if (nb_arg < 3) {
        write(2, "repeat: Too few arguments.\n", 27);
        return (1);
    }
    for (int i = 0; arg_number[i]; i++) {
        if ('0' > arg_number[i] || arg_number[i] > '9') {
            write (2, "repeat: Badly formed number.\n", 29);
            return (1);
        }
    }
    return (0);
}

int my_repeat(char **all_command, my_minishell_t *my_minishell)
{
    int nb_arg = 0;
    int nb_repeat = 0;
    char *command_line = NULL;

    for (; all_command[nb_arg]; nb_arg++);
    if (handle_error(nb_arg, all_command[1]) != 0)
        return (1);
    nb_repeat = my_getnbr(all_command[1]);
    command_line = rebuild_command_line(all_command + 2);
    for (int i = 0; i < nb_repeat; i++) {
        handle_pipe(my_minishell, command_line);
        if (my_strncmp(command_line, "repeat", 5) == 0
        && my_minishell->exit != 0)
            return (1);
    }
    return (0);
}
