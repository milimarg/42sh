/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** perfect_malloc_two_words
*/

#include "../../include/minishell.h"

int perfect_malloc_two_words_two(int stat, int count, int* perfect, int index)
{
    if (stat == 0 && count > 0) {
        perfect[index] = count;
        index++;
    }
    return (index);
}

int *perfect_malloc_two_words(char *str, char *word[2], int presence)
{
    int count = 0;
    int index = 0;
    int stat = 0;
    int *perfect = malloc(sizeof(int) * (presence + 2));
    for (int i = 0; str[i] != '\0' && index <= presence; i++) {
        if (strcmp_word(str, i, word[0]) || strcmp_word(str, i, word[1])) {
            i += (my_strlen(word[0]) - 1);
            index = perfect_malloc_two_words_two(stat, count, perfect, index);
            count = 0;
            stat = 1;
        } else {
            count++;
            stat = 0;
        }
    }
    perfect[index] = count;
    return (perfect);
}
