/*
** EPITECH PROJECT, 2023
** test
** File description:
** strcmp_word
*/

#include "../../include/minishell.h"

int strcmp_word(char *str, int index, char *word)
{
    int base = index;
    int i = 0;
    while (str[index] != '\0' && index < (my_strlen(word) + base)) {
        if (str[index] != word[i])
            return (0);
        i++;
        index++;
    }
    if (i == my_strlen(word)) {
        return (1);
    } else
        return (0);
}
