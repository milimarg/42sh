/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** quote_check
*/

#include "../../include/minishell.h"

int quote_check(char const *str, int i)
{
    static bool quote = false;
    if (quote == true) {
        if (str[i] == '\'' || str[i] == '\"') {
            quote = false;
            return 2;
        }
        return 1;
    }
    if (str[i] == '\'' || str[i] == '\"') {
        quote = true;
        return 1;
    }
    return 0;
}
