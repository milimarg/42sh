/*
** EPITECH PROJECT, 2022
** load_2d_arr_from_file.c
** File description:
** bsq
*/

#include "my.h"

char **load_2d_arr_from_file(char *map, int nb_rows, int nb_cols, int header)
{
    int i = header, x = 0 , y = 0;
    char **tab = malloc(sizeof(char*) * (nb_cols + 1));
    for (int a = 0; a < nb_cols; a++) {
        tab[a] = malloc(nb_rows + 2);
    }
    for (; map[i] != '\0'; i++) {
        if (map[i] != '\n') {
            tab[y][x] = map[i];
            x++;
        } else {
            tab[y][x] = map[i];
            tab[y][x + 1] = '\0';
            y++;
            x = 0;
        }
    }
    tab[y] = NULL;
    return (tab);
}
