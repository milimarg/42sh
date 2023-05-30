/*
** EPITECH PROJECT, 2022
** load_file_in_mem
** File description:
** BSQ
*/

#include "my.h"

char *load_file_in_mem(char const *filepath)
{
    struct stat sb;
    stat(filepath, &sb);
    int size = sb.st_size;
    char *buff = malloc(sizeof(char) * (size + 1));
    int cat = open(filepath,O_RDONLY, S_IRWXU);
    if (cat <= 0) {
        buff[0] = 0;
        return (buff);
    }
    int lire = read(cat, buff, size);
    buff[size] = '\0';
    close(cat);
    return (buff);
}
