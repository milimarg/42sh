/*
** EPITECH PROJECT, 2023
** test
** File description:
** perfect_malloc
*/

#include "../../include/minishell.h"

int perfect_malloc_two(int stat, int count, int* perfect, int index)
{
    if (stat == 0 && count > 0) {
        perfect[index] = count;
        index++;
    }
    return (index);
}

int *perfect_malloc(char *str, char *word, int presence)
{
    int count = 0;
    int index = 0;
    int stat = 0;
    int *perfect = malloc(sizeof(int) * (presence + 2));
    for (int i = 0; str[i] != '\0' && index <= presence; i++) {
        if (strcmp_word(str, i, word)) {
            i += (my_strlen(word) - 1);
            index = perfect_malloc_two(stat, count, perfect, index);
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
