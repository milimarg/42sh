/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_exit
*/

#include "../../include/minishell.h"

int count_nbr_in_char(char *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9')
            count++;
    }
    if (count == my_strlen(str))
        return (0);
    if (count >= 0 && count < my_strlen(str) && (str[0] < '0' || str[0] > '9'))
        return (-1);
    else
        return (1);
}

int my_exit_two(char **all_command, my_minishell_t *my_minishell)
{
    int count_nbr = count_nbr_in_char(all_command[1]);
    if (my_strncmp(all_command[1], "-1", 2) == 0) {
        my_minishell->end = 1;
        my_minishell->previous_exit = 255;
        return (0);
    }
    switch (count_nbr) {
        case -1 : write(2, "exit: Expression Syntax.\n", 25); return (1);
        case 0 : my_minishell->previous_exit = my_getnbr(all_command[1]);
        my_minishell->end = 1; break;
        case 1 : write(2, "exit: Badly formed number.\n", 27) ; return (1);
    }
    if (isatty(0) && count_nbr == 0)
        write(2, "exit\n", 5);
}

int my_exit(char **all_command, my_minishell_t *my_minishell)
{
    if (all_command[1] == NULL) {
        my_minishell->end = 1;
        if (isatty(0))
            write(2, "exit\n", 5);
    } else {
        return (my_exit_two(all_command, my_minishell));
    }
    return (0);
}
