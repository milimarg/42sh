/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** count_my_words
*/

#include "../../include/minishell.h"

static int words_check(char const *str, int i, int quote)
{
    static bool state = false;

    if (quote == 1 && state == true) {
        state = false;
        return 1;
    }
    if (str[i] == ' ' || str[i] == '\t') {
        if (state == true) {
            state = false;
            return 1;
        }
        return 0;
    }
    if (quote == 0)
        state = true;
    if (!str[i + 1])
        state = false;
    return 0;
}

int count_my_words(char const *str)
{
    int words = 0;
    int quote = 0;
    int check = 0;
    int i = 0;

    for (; str[i] == ' ' || str[i] == '\t'; i++);
    for (; str[i] != '\0'; i++) {
        quote = quote_check(str, i);
        if (quote != 0)
            words += (quote - 1);
        check = words_check(str, i, quote);
        if (check != 0)
            words += check;
    }
    if (str[i - 1] != ' ' && str[i - 1] != '\t' &&
        str[i - 1] != '\'' && str[i - 1] != '\"')
        words++;
    return (words);
}
