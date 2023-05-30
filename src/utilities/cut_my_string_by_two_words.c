/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** cut_my_string_by_two_words
*/

#include "../../include/minishell.h"

int count_my_two_word_two(int stat, int count, int presence)
{
    if (stat == 0 && count > 0) {
        presence++;
    }
    return (presence);
}

int count_my_two_word(char *str, char *word[2])
{
    int presence = 0;
    int count = 0;
    int stat = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        for (; quote_check(str, i) != 0; i++);
        i = (str[i] == '\0') ? i - 1 : i;
        if (strcmp_word(str, i, word[0]) || strcmp_word(str, i, word[1]))  {
            i += my_strlen(word[0]) - 1;
            presence = count_my_two_word_two(stat, count, presence);
            count = 0;
            stat = 1;
        } else {
            count++;
            stat = 0;
        }
    }
    if (stat == 1)
        presence--;
    return (presence);
}

int cut_my_string_by_two_word_three(int stat, int k, int j, char **new_tab)
{
    if (stat == 0 && k > 0) {
        new_tab[j][k] = '\0';
        while (new_tab[j][k - 1] == ' ' || new_tab[j][k - 1] == '\t') {
            k--;
            new_tab[j][k] = '\0';
        }
        j++;
    }
    return (j);
}

void cut_my_string_by_two_word_two(char *str, char *word[2], int presence,
char **new_tab)
{
    int stat = 0; int k = 0; int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        for (; quote_check(str, i) != 0; i++)
            new_tab[j][k++] = str[i];
        k = (str[i] == '\0') ? k - 1 : k;
        i = (str[i] == '\0') ? i - 1 : i;
        if (strcmp_word(str, i, word[0]) || strcmp_word(str, i, word[1])) {
            i = (str[i + 2] == ' ' || str[i + 2] == '\t') ?
            ignore_space_and_tabs(i + 2, str) : i + 1;
            j = cut_my_string_by_two_word_three(stat, k, j, new_tab);
            k = 0;
            stat = 1;
        } else {
            new_tab[j][k++] = str[i];
            stat = 0;
        }
    }
    new_tab[j][k] = (stat == 0) ? '\0' : new_tab[j][k];
}

char **cut_my_string_by_two_word(char *str, char *word[2])
{
    int presence = count_my_two_word(str, word);
    char **new_tab = malloc(sizeof(char *) * (presence + 2));
    int *perfect = perfect_malloc_two_words(str, word, presence);

    for (int i = 0; i <= presence; i++) {
        new_tab[i] = malloc(sizeof(char) * (perfect[i] + 1));
    }
    cut_my_string_by_two_word_two(str, word, presence, new_tab);
    new_tab[presence + 1] = NULL;
    free(perfect);
    return (new_tab);
}
