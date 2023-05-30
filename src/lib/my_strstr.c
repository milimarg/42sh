/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** uf
*/

#include "my.h"

char *my_strstr(char *haystack, char const *needle)
{
    int needle_len = my_strlen(needle);

    for (int i = 0; haystack[i]; i++)
        if (my_strncmp(&haystack[i], needle, needle_len) == 0)
            return (&haystack[i]);
    return (NULL);
}
