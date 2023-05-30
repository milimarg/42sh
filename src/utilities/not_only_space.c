/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** not_only_space
*/

#include "../../include/minishell.h"

int not_only_space(char *buff)
{
    int symb = 0;

    if (buff == NULL)
        return (-1);
    for (int i = 0; buff[i] != '\n' && buff[i]; i++) {
        if (buff[i] != ' ')
            symb++;
    }
    if (symb > 0)
        return (0);
    else
        return (-1);
}
