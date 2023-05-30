/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** handle_my_signals
*/

#include "../../include/minishell.h"

void handler(int signum)
{
}

void handle_my_signals(my_minishell_t *my_minishell)
{
    signal(SIGINT, &handler);
}
