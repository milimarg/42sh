/*
** EPITECH PROJECT, 2023
** ANT_GIANT
** File description:
** lowest
*/

#include "my.h"

int *lowest_in_int_tab(int *symb_tab)
{
    int *list = malloc(sizeof(int) * 2);
    if (!list)
        return (NULL);
    int lower = max_in_int_tab(symb_tab);
    int index = 0;
    for (int i = 0; i < 128; i++) {
        if (symb_tab[i] <= lower && symb_tab[i] > 0) {
            lower = symb_tab[i];
            index = i;
        }
    }
    list[0] = lower;
    list[1] = index;
    symb_tab[index] = 0;
    return (list);
}
