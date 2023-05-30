/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** separate_args_spe
*/

#include "../../include/minishell.h"

static int ignore_my_spe(char const *str, int i, char spe)
{
    while (str[i] != '\0' &&
        (str[i] == spe || str[i] == ' ' || str[i] == '\t'))
        i++;
    return (i - 1);
}

static void remove_space(char **tab, int y, int x, char spe)
{
    tab[y][x] = '\0';
    x--;
    if (x < 0)
        return;
    while (tab[y][x] == ' ' || tab[y][x] == '\t' || tab[y][x] == spe) {
        tab[y][x] = '\0';
        x--;
    }
}

static int ignore_space(int quote, char const *str, int i, char spe)
{
    if (quote == 0 && (str[i] == ' ' || str[i] == '\t')) {
        while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t')) {
            i++;
        }
        i--;
    }
    return (i);
}

static void read_words_spe(char const *str, char **tab, char spe, int i)
{
    int quote = 0;
    int y = 0;
    int x = 0;
    for (; str[i] == spe; i++);
    for (; str[i] != '\0'; i++) {
        quote = quote_check(str, i);
        if (quote == 0 && str[i] == spe) {
            remove_space(tab, y, x, spe);
            y++;
            x = 0;
            i = ignore_my_spe(str, i, spe);
        } else {
            tab[y][x] = str[i];
            i = ignore_space(quote, str, i, spe);
            x++;
        }
    }
    if (x > 0)
        remove_space(tab, y, x, spe);
}

char **separate_args_spe(char const *str, char spe)
{
    int words = 0;
    char **tab = NULL;

    if (str == NULL)
        return (NULL);
    words = count_my_spe(str, spe);
    tab = malloc(sizeof(char *) * (words + 1));
    for (int i = 0; i < words; i++)
        tab[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (words != 0)
        read_words_spe(str, tab, spe, 0);
    tab[words] = NULL;
    return tab;
}
