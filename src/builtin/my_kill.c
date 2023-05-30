/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_kill.c
*/

#include "../../include/minishell.h"

static int is_str_a_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return (0);
        }
    }
    return (1);
}

static int check_signum_is_valid(char *name, int signame_len)
{
    if (!is_str_a_number(name)) {
        write(2, name, signame_len);
        write(2, ": Unknown signal; kill -l lists signals.\n", 41);
        return (-1);
    }
    return (atoi(name));
}

static int get_signum_from_name(char *signame, const char *names[])
{
    int signum = 0;
    int signame_len = strlen(signame);

    for (int i = 0; names[i] != NULL; i++) {
        if (!strcmp(signame, names[i])) {
            return (i + 1);
        }
    }
    signum = check_signum_is_valid(signame, signame_len);
    return (signum);
}

static void kill_processes(char **all_command, const char *names[])
{
    int signum = 0;

    if (all_command[1][0] != '-')
        signum = SIGTERM;
    else
        signum = get_signum_from_name(&all_command[1][1], names);
    if (signum == 0 || signum > 32)
        return;
    for (int i = 1 + (all_command[1][0] == '-'); all_command[i] != NULL; i++) {
        if (!is_str_a_number(all_command[i])) {
            write(2, "kill: Arguments should be jobs or process id's.\n", 48);
            continue;
        }
        if (kill(atoi(all_command[i]), signum) == -1) {
            write(1, all_command[i], strlen(all_command[i]));
        }
    }
}

int my_kill(char **all_command, my_minishell_t *my_minishell)
{
    const char *names[] = {"HUP", "INT", "QUIT", "ILL", "TRAP", "IOT", "BUS",
    "FPE", "KILL", "USR1", "SEGV", "USR2", "PIPE", "ALRM", "TERM", "STKFLT",
    "CHLD", "CONT", "STOP", "TSTP", "TTIN", "TTOU", "URG", "XCPU", "XFSZ",
    "VTALRM", "PROF", "WINCH", "POLL", "PWR", "SYS", NULL};
    const int names_len[] = {3, 3, 4, 3, 4, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 6, 4,
    4, 4, 4, 4, 4, 3, 4, 4, 5, 4, 5, 4, 3, 3};

    if (all_command[0] != NULL && all_command[1] == NULL) {
        write(2, "kill: Too few arguments.\n", 25);
        return (1);
    }
    if (!strcmp(all_command[1], "-l")) {
        for (int i = 0; names[i] != NULL; i++) {
            write(1, names[i], names_len[i]);
            write(1, (names[i + 1] == NULL) ? "\n" : " ", 1);
        }
    } else
        kill_processes(all_command, names);
    return (0);
}
