/*
** EPITECH PROJECT, 2023
** B-CPE-200-STG-2-1-bscorewar-augustin.grosnon
** File description:
** copy_tab
*/

#include "my.h"

static void free_word_array_elems_error(char **arr, int max_index)
{
    for (int i = 0; i < max_index; i++) {
        free(arr[i]);
    }
}

char **copy_tab(char **tab)
{
    int tab_size = 0;
    char **new_tab = NULL;

    for (; tab[tab_size]; tab_size++);
    new_tab = malloc(sizeof(char *) * (tab_size + 1));
    if (new_tab == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        new_tab[i] = my_strdup(tab[i]);
        if (new_tab[i] == NULL) {
            free_word_array_elems_error(new_tab, i);
            free(new_tab);
            return (NULL);
        }
    }
    new_tab[tab_size] = NULL;
    return (new_tab);
}
