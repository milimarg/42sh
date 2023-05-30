/*
** EPITECH PROJECT, 2022
** find_column
** File description:
** BSQ
*/

int find_cols(char *buff)
{
    int j = 0;
    int count = 0;
    while (buff[j] != '\0') {
        if (buff[j] == '\n')
            count++;
        j++;
    }
    return (count);
}
