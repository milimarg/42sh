/*
** EPITECH PROJECT, 2023
** lib
** File description:
** char ** my_str_to_word_array
*/

#include "my.h"

static int count_my_words_spe(char const *str, char spe)
{
    int words = 0;
    int state = 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == spe){
            state = 84;
        }
        if (str[i] != spe && state == 84) {
            words++;
            state = 0;
        }
    }
    return (words);
}

static int find_biggest_word_spe(char const *str, char spe)
{
    int lenght = 0;
    int biggest = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != spe)
            lenght++;
        else {
            biggest = (lenght > biggest) ? lenght : biggest;
            lenght = 0;
        }
    }
    biggest = (lenght > biggest) ? lenght : biggest;
    return (biggest);
}

static int ignore_my_non_alpha_spe(char const *str, int i, int add, char spe)
{
    while (str[i + 1] != '\0' && str[i + add] == spe)
        i++;
    return (i);
}

static char **my_str_to_word_array_spe_two(char *str, char spe, char **tab,
int words)
{
    int i = ignore_my_non_alpha_spe(str, 0, 0, spe);
    int a = 0;
    int b = 0;
    for (; str[i] != '\0' && b < words; i++) {
        if (str[i] != spe) {
            tab[b][a] = str[i];
            a++;
        } else {
            tab[b][a] = '\0';
            b++;
            a = 0;
            i = ignore_my_non_alpha_spe(str, i, 1, spe);
        }
    }
    (b < words) ? tab[b][a] = '\0' : 0;
    tab[words] = NULL;
    return (tab);
}

char **my_str_to_word_array_spe(char *str, char spe)
{
    if (str == NULL)
        return (NULL);
    int words = count_my_words_spe(str, spe);
    char **tab = malloc(sizeof(char *) * (words + 1));
    int biggest_word = find_biggest_word_spe(str, spe);
    for (int i = 0; i < words; i++) {
        tab[i] = malloc(sizeof(char) * (biggest_word + 1));
    }
    my_str_to_word_array_spe_two(str, spe, tab, words);
}
