/*
** EPITECH PROJECT, 2022
** find_line
** File description:
** bsq
*/

int verify_biggest (int line, int biggest_line)
{
    if (biggest_line < line) {
        return (line);
    } else {
        return (biggest_line);
    }
}

int find_biggest_line(char *buff)
{
    int l = 0;
    int biggest_l = 0;
    for (int a = 0;buff[a] != '\0'; a++){
        if (buff[a] != '\n') {
            l++;
        } else {
            biggest_l = verify_biggest(l, biggest_l);
            l = 0;
        }
    }
    return (biggest_l);
}
