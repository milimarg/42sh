/*
** EPITECH PROJECT, 2023
** count_symb
** File description:
** my_antman
*/

#include "my.h"

int *count_symb(char *buff)
{
    int *counter = malloc(sizeof(int) * (128));

    if (!counter)
        return (NULL);
    for (int i = 0; i < 128; i++)
        counter[i] = 0;
    for (int j = 0; buff[j] != '\0'; j++) {
        int temp = buff[j];
        counter[temp]++;
    }
    return (counter);
}
