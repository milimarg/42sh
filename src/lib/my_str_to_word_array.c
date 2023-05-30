/*
** EPITECH PROJECT, 2023
** lib
** File description:
** char ** my_str_to_word_array
*/

#include "my.h"

static int count_my_words(char const *str)
{
    int words = 0;
    int state = 84;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_alpha(str[i]) == 84){
            state = 84;
        }
        if (my_is_alpha(str[i]) == 0 && state == 84) {
            words++;
            state = 0;
        }
    }
    return (words);
}

static int find_biggest_word(char const *str)
{
    int lenght = 0;
    int biggest = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_is_alpha(str[i]) == 0)
            lenght++;
        else {
            biggest = (lenght > biggest) ? lenght : biggest;
            lenght = 0;
        }
    }
    biggest = (lenght > biggest) ? lenght : biggest;
    return (biggest);
}

static char **malloc_my_tab_str(char const *str, int words)
{
    char **tab = malloc(sizeof(char *) * (words + 1));
    int biggest_word = find_biggest_word(str);
    for (int i = 0; i < words; i++) {
        tab[i] = malloc(sizeof(char) * (biggest_word + 1));
    }
    return (tab);
}

static int ignore_my_non_alpha(char const *str, int i, int add)
{
    while (str[i + 1] != '\0' && my_is_alpha(str[i + add]) == 84)
        i++;
    return (i);
}

char **my_str_to_word_array(char const *str)
{
    int a = 0;
    int b = 0;
    int i = 0;
    int words = count_my_words(str);
    char **tab = malloc_my_tab_str(str, words);
    i += ignore_my_non_alpha(str, i, 0);
    for (; str[i] != '\0'; i++) {
        if (my_is_alpha(str[i]) == 0) {
            tab[b][a] = str[i];
            a++;
        } else {
            tab[b][a] = '\0';
            b++;
            a = 0;
            i = ignore_my_non_alpha(str, i, 1);
        }
    }
    tab[b][a] = '\0';
    tab[words] = NULL;
    return (tab);
}
