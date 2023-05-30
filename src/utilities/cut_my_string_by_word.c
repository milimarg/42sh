/*
** EPITECH PROJECT, 2023
** test
** File description:
** cut_my_string_by_word
*/

#include "../../include/minishell.h"

int count_my_word_two(int stat, int count, int presence)
{
    if (stat == 0 && count > 0) {
        presence++;
    }
    return (presence);
}

int count_my_word(char *str, char *word)
{
    int presence = 0;
    int count = 0;
    int stat = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        for (; quote_check(str, i) != 0; i++);
        if (strcmp_word(str, i, word)) {
            i += my_strlen(word) - 1;
            presence = count_my_word_two(stat, count, presence);
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

int cut_my_string_by_word_three(int stat, int k, int j, char **new_tab)
{
    if (stat == 0 && k > 0) {
        new_tab[j][k] = '\0';
        j++;
    }
    return (j);
}

void cut_my_string_by_word_two(char *str, char *word, int presence,
char **new_tab)
{
    int stat = 0;
    int k = 0;
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        for (; quote_check(str, i) != 0; i++)
            new_tab[j][k++] = str[i];
        if (strcmp_word(str, i, word)) {
            i += my_strlen(word) - 1;
            j = cut_my_string_by_word_three(stat, k, j, new_tab);
            k = 0;
            stat = 1;
        } else {
            new_tab[j][k++] = str[i];
            stat = 0;
        }
    }
    if (stat == 0)
        new_tab[j][k] = '\0';
    new_tab[presence + 1] = NULL;
}

char **cut_my_string_by_word(char *str, char *word)
{
    int presence = count_my_word(str, word);
    char **new_tab = malloc(sizeof(char *) * (presence + 2));
    int *perfect = perfect_malloc(str, word, presence);

    for (int i = 0; i <= presence; i++) {
        new_tab[i] = malloc(sizeof(char) * (perfect[i] + 1));
    }
    cut_my_string_by_word_two(str, word, presence, new_tab);
    free(perfect);
    return (new_tab);
}
