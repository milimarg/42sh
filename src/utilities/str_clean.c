/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** str_clean
*/

#include "../../include/minishell.h"

static int biggest_words(char const *str)
{
    int biggest = 0;
    int tmp = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            biggest = (biggest < tmp) ? tmp : biggest;
            tmp = 0;
        } else {
            tmp++;
        }
    }
    biggest = (biggest < tmp) ? tmp : biggest;
    return (biggest);
}

static int count_words(char const *str)
{
    int count = 0;
    bool stat = false;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t') {
            stat = false;
            continue;
        }
        if (stat == false) {
            count++;
            stat = true;
        }
    }
    return (count);
}

char *str_clean(char const *str)
{
    int words = count_words(str);
    int big = biggest_words(str);
    char *clean_str = malloc(sizeof(char) * ((words * big) + words + 1));
    int i = 0;
    int a = 0;
    for (;str[i] == ' ' || str[i] == '\t'; i++);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t') {
            clean_str[a] = str[i];
            a++;
            continue;
        }
        if (a > 0 && clean_str[a - 1] != ' ') {
            clean_str[a] = ' ';
            a++;
        }
    }
    clean_str[a] = '\0';
    return (clean_str);
}
