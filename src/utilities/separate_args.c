/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** separate_args
*/

#include "../../include/minishell.h"

static int ignore_space_and_tabs_and_tab(char const *str, int i)
{
    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
        i++;
    return i;
}

static int copy_quote(char const *str, char **tab, int i, int *idx)
{
    tab[idx[0]][idx[1]] = str[i];
    idx[1]++;
    i++;
    while (str[i] != '\'' && str[i] != '\"' && str[i] != '\0') {
        tab[idx[0]][idx[1]] = str[i];
        idx[1]++;
        i++;
    }
    tab[idx[0]][idx[1]] = str[i];
    idx[1]++;
    i++;
    tab[idx[0]][idx[1]] = '\0';
    idx[0]++;
    idx[1] = 0;
    i = ignore_space_and_tabs_and_tab(str, i);
    return i - 1;
}

static int read_words_two(char const *str, char **tab, int i, int *idx)
{
    if (str[i] == '\'' || str[i] == '\"') {
        if (idx[1] > 0) {
            tab[idx[0]][idx[1]] = '\0';
            idx[0]++;
            idx[1] = 0;
        }
        i = copy_quote(str, tab, i, idx);
        return i;
    }
    tab[idx[0]][idx[1]] = str[i];
    idx[1]++;
    return i;
}

static void read_words(char const *str, char **tab)
{
    int *idx = malloc(sizeof(int) * 2);
    idx[0] = 0;
    idx[1] = 0;
    int i = ignore_space_and_tabs_and_tab(str, 0);
    for (; str[i] != '\0'; i++) {
        if ((str[i] == ' ' || str[i] == '\t') && idx[1] > 0) {
            tab[idx[0]][idx[1]] = '\0';
            idx[0]++;
            idx[1] = 0;
            i = ignore_space_and_tabs_and_tab(str, i) - 1;
            continue;
        }
        i = read_words_two(str, tab, i, idx);
    }
    if (idx[1] > 0)
        tab[idx[0]][idx[1]] = '\0';
}

char **separate_args(char const *str)
{
    int words = 0;
    char **tab = NULL;

    if (str == NULL)
        return (NULL);
    words = count_my_words(str);
    tab = malloc(sizeof(char *) * (words + 1));
    for (int i = 0; i < words; i++)
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    read_words(str, tab);
    tab[words] = NULL;
    return tab;
}
