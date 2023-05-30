/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** count_my_spe
*/

#include "../../include/minishell.h"

static int ignore_my_spe(char const *str, int i, char spe)
{
    int base = i;

    while (str[i + 1] != '\0' && str[i] == spe)
        i++;
    if (base == i)
        return (i);
    else
        return (i - 1);
}

char last_char(char const *str, int i)
{
    while (str[i] == '\t' || str[i] == ' ')
        i--;
    return (str[i]);
}

int count_my_spe(char const *str, char spe)
{
    int words = 0;
    int quote = 0;
    int i = 0;

    for (; str[i] == spe; i++);
    for (; str[i] != '\0'; i++) {
        quote = quote_check(str, i);
        if (quote == 0 && str[i] == spe) {
            words++;
            i = ignore_my_spe(str, i, spe);
        }
    }
    if (last_char(str, i - 1) != spe ||
        (words == 0 && last_char(str, i - 1) != spe))
        words++;
    return (words);
}
