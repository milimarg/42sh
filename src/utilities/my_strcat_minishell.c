/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_strcat_minishell
*/

#include "../../include/minishell.h"

int my_strlen_base(char const *str)
{
    int a = 0;
    while (str[a] != '\0') {
        str[a];
        a++;
    }
    if (str[a - 1] != '/')
        a++;
    return (a);
}

char *my_strcat_minishell(char *str_one, char const *str_two)
{
    int base_len = my_strlen_base(str_one);
    int file_len = my_strlen(str_two);
    char *result = malloc(sizeof(char) * (base_len + file_len + 1));
    int i = 0;
    while (str_one[i] != '\0') {
        result[i] = str_one[i];
        i++;
    }
    if (str_one[i - 1] != '/' ) {
        result[i] = '/';
        i++;
    }
    for (int a = 0; str_two[a] != '\0'; a++) {
        result[i] = str_two[a];
        i++;
    }
    result[i] = '\0';
    return (result);
}
