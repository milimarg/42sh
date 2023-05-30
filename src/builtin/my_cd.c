/*
** EPITECH PROJECT, 2023
** minishell1
** File description:
** my_cd
*/

#include "../../include/minishell.h"

char *ignore_my_point(char *file)
{
    int i = 0;
    for (; (my_strlen(file) >= 3 + (3 * i)) && file[(3 * i)] == '.'
            && file[(3 * i + 1)] == '.' && file[(3 * i) + 2] == '/'; i++) {
    }
    int j = 0;
    for (j = (i * 3); file[j] != '\0'; j++);
    char *tmp = malloc(sizeof(char) * (j + 1));
    int a = 0;
    for (j = (i * 3); file[j] != '\0'; j++) {
        tmp[a] = file[j];
        a++;
    }
    tmp[a] = '\0';
    return (tmp);
}

int verify_if_file_existed(char const *file)
{
    struct stat path_stat;
    if (stat(file, &path_stat) != 0) {
        write(2, file, my_strlen(file));
        write(2, ": No such file or directory.\n", 29);
        return (1);
    }
    if (S_ISDIR(path_stat.st_mode) == 1) {
        if (access(file, X_OK) == -1) {
            write(2, file, my_strlen(file));
            write(2, ": Permission denied.\n", 21);
            return (1);
        }
        return (0);
    } else {
        write(2, file, my_strlen(file));
        write(2, ": Not a directory.\n", 19);
        return (1);
    }
}

int go_to_file_two(my_minishell_t *min, char *file, char *back, char *original)
{
    char **tmp = malloc(sizeof(char *) * 2);
    file = ignore_my_point(file);
    if ((file[0] == '\0') || (file[0] == '.' && file[1] == '.' &&
        file[2] == '\0')) {
        tmp[0] = back;
    } else
        tmp[0] = my_strcat_minishell(back, file);
    tmp[1] = NULL;
    if (verify_if_file_existed(original) == 0) {
        if (original[0] != '/') {
            min->pos->oldpwd = min->pos->pwd;
            min->pos->pwd = tmp[0];
        } else {
            min->pos->oldpwd = min->pos->pwd;
            min->pos->pwd = original;
        }
        chdir(min->pos->pwd);
        return (0);
    }
    return (1);
}

int go_to_file(my_minishell_t * my_minishell, char *file)
{
    char *back = my_minishell->pos->pwd;
    for (int i = 0; (my_strlen(file) >= 3 + (3 * i)) && file[(3 * i)] == '.'
                    && file[(3 * i) + 1] == '.' &&
                    file[(3 * i) + 2] == '/'; i++) {
        char **temp = back_from_path(back);
        back = temp[0];
    }
    return (go_to_file_two(my_minishell, file, back, file));
}

int my_cd(char **all_command, my_minishell_t *my_minishell)
{
    int res = 0;
    for (; all_command[res]; res++);
    if (res >= 3) {
        write(2, "cd: Too many arguments.\n", 24);
        return (1);
    }
    if ((!all_command[1]) || (all_command[1] &&
    my_strncmp(all_command[1], "~", 1) == 0))
        return (path_to_home(my_minishell));
    if (my_strncmp(all_command[1], "-a", 2) == 0) {
        write(2, "Usage: cd [-plvn][-|<dir>].\n", 28);
        return (1);
    }
    if (my_strncmp(all_command[1], "-", 1) == 0)
        return (path_to_previous(my_minishell));
    if (my_strncmp(all_command[1], "..", 2) == 0)
        return (path_to_back(my_minishell));
    return (go_to_file(my_minishell, all_command[1]));
}
