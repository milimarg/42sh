/*
** EPITECH PROJECT, 2023
** B-PSU-200-STG-2-1-42sh-augustin.grosnon
** File description:
** my_whereis_two
*/

#include "../../include/minishell.h"

int my_strncmp_whereis(char const *s1, char const *s2, int n);
char *set_string(char *dir_path, char *file_name);

void display_whereis_help(void)
{
    my_printf("\nUsage:\n"
    " whereis [options] [-BMS <dir>... -f] <name>\n\n"
    "Options:\n"
    " -b\tsearch only for binaries\n"
    " -B <dirs>\tdefine binaries lookup path\n"
    " -m\tsearch only for manual and infos\n"
    " -M <dirs>\tdefine man and info lookup path\n"
    " -s\tsearch only for sources\n"
    " -S <dirs>\tdefine sources lookup path\n"
    " -f\tterminate <dirs> argument list\n"
    " -u\tsearch or unusual entries\n"
    " -l\toutput effective lookup paths\n\n"
    " -h, --help\tdisplay this help\n"
    " -V, --version\tdisplay version\n\n"
    "For more details, see whereis(1).\n"
    );
}

int find_man_page(const char *searched_str, char *dir_path)
{
    DIR *dir = opendir(dir_path);
    struct dirent *entry = NULL;
    char *full_string = NULL;

    if (dir == NULL)
        return (0);
    while (entry = readdir(dir)) {
        if (my_strncmp_whereis(entry->d_name, searched_str,
        my_strlen(searched_str)) == 0) {
            full_string = set_string(dir_path, entry->d_name);
            write(1, " ", 1);
            write(1, full_string, my_strlen(full_string));
            free(full_string);
        }
    }
    closedir(dir);
    return (0);
}
