/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** main
*/

#include "../include/minishell.h"

void enable_raw_mode(void)
{
    struct termios raw = {0};

    tcgetattr(1, &raw);
    raw.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(1, TCSAFLUSH, &raw);
}

void disable_raw_mode(void)
{
    struct termios normal = {0};

    tcgetattr(1, &normal);
    normal.c_lflag |= ECHO | ICANON;
    tcsetattr(1, TCSAFLUSH, &normal);
}

int main(int argc, char **argv, char **env)
{
    if (argc == 2) {
        my_printf("Option inconnue: %c%s%c\nSyntaxe: ./42sh\n",
        34, argv[1], 34);
        return (0);
    }
    if (argc != 1)
        return (84);
    int error = 0;
    my_minishell_t* my_minishell = create_my_minishell(env);
    if (isatty(0))
        enable_raw_mode();
    error = loop_minishell(my_minishell);
    free_my_minishell(my_minishell);
    if (isatty(0))
        disable_raw_mode();
    return (error);
}
