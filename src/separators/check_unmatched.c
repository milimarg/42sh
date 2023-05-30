/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-minishell2-augustin.grosnon
** File description:
** check_unmatched
*/

#include "../../include/minishell.h"

void find_which_quote(int simple_quote, int double_quote, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\'' && simple_quote) {
            write(2, "Unmatched '\''.\n", 15);
            return;
        }
        if (str[i] == '\"' && double_quote) {
            write(2, "Unmatched '\"'.\n", 15);
            return;
        }
    }
}

int check_unmatched(my_minishell_t *my_minishell, char const *str)
{
    int simple_quote = 0;
    int double_quote = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\'')
            simple_quote = !(simple_quote);
        if (str[i] == '\"')
            double_quote = !(double_quote);
    }
    if ((simple_quote + double_quote) % 2 == 1) {
        find_which_quote(simple_quote, double_quote, str);
        my_minishell->exit = 1;
        return 1;
    }
    return 0;
}
