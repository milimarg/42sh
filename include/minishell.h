/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#ifndef MINISHELL_H
    #define MINISHELL_H
    #include "../src/lib/my.h"
    #include <termios.h>
    #include <string.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <glob.h>

// structure pour le cd
typedef struct my_path_s {
    char *pwd;
    char *oldpwd;
    char *home;
    char **path;
}my_path_t;

//structure de l'environnement
typedef struct my_env_s {
    char *name;
    char **path;
    char *variable;
    int status;
    struct my_env_s *next;
}my_env_t;

//structure de l'historique
typedef struct history_s {
    char string[1024];
    int len;
    struct history_s *next;
    struct history_s *prev;
} history_t;

//structure de la gestion de ligne
typedef struct line_s {
    char string[1024];
    int len;
    int index;
    char buffer;
    history_t *history_head;
    history_t *current_history;
} line_t;

//structure de l'alias
typedef struct alias_s {
    char *string;
    char *name;
    char *command;
    struct alias_s *next;
} alias_t;

// structure des variables
typedef struct variable_s {
    char *string;
    char *name;
    char *value;
    struct variable_s *next;
} variable_t;

// structure du minishell
typedef struct my_minishell_t {
    char **argu;
    char **env;
    unsigned int end;
    unsigned int exit;
    unsigned int previous_exit;
    unsigned int error;
    struct my_env_s *my_env;
    struct my_path_s *pos;
    line_t *struct_line;
    alias_t *struct_alias;
    variable_t *struct_set;
    char *command_line;
    char **last_path;
    size_t len;
    int err;
    int oldfd;
    int dup_zero;
    int dup_one;
    int dollar_index;
    int last_pid;
} my_minishell_t;

// FONCTIONS UTILITAIRES
/**
 * @brief Look in the str if a word is present at a specific index
 * @param str String you want to test
 * @param index index in the string where you want to start compare
 * @param word word you want to find
 * @return 0 if succeeds and 1 if failed
**/
int strcmp_word(char *str, int index, char *word);
/**
 * @brief Counts the size of all words in the string except the word "word"
 * @param str String you want to test
 * @param word Word you want to cut in the str
 * @param presence How many time the word is present
 * @return Lenght of every other word
**/
int *perfect_malloc(char *str, char *word, int presence);
int *perfect_malloc_two_words(char *str, char *word[2], int presence);
/**
 * @brief Cuts a str each time a word is present
 * @param str String you want to cut
 * @param word Word you want to cut in the str
 * @return Tab with every word separated
**/
char **cut_my_string_by_word(char *str, char *word);
char **cut_my_string_by_two_word(char *str, char *word[2]);
// (strcpy modifié rajoutant un '/' si non présent entre la base et le file)
/**
 * @brief Free a tab
 * @param tab Tab you want to free
**/
void free_my_tab(char **tab);
/**
 * @brief Concatenated 2 str and add a bar if not already present between them
 * @param str_one First string
 * @param str_two Second string
 * @return Result of the 2 strings concatenated
**/
char *my_strcat_minishell(char *str_one, char const *str_two);
char **separate_args(char const *str);
int count_my_words(char const *str);
char **separate_args_spe(char const *str, char spe);
int count_my_spe(char const *str, char spe);
int quote_check(char const *str, int i);

// création et destruction de la structure
my_minishell_t *create_my_minishell(char **env);
void initialize_pwd(my_minishell_t *my_minishell);
void free_my_minishell(my_minishell_t *my_minishell);

// boucle général du minishell
int loop_minishell(my_minishell_t *my_minishell);
void print_my_prompt(my_minishell_t* my_minishell);
void handle_my_signals(my_minishell_t *my_minishell);

// exécution des commandes
void minishell_ope(my_minishell_t *my_minishell, char *command);
void switch_my_exit(my_minishell_t *my_minishell);
void command_not_found(my_minishell_t *min, char *command, char **my_env);

// parsing
int not_only_space(char *buff);
char **split_my_command_line(char *command_line, char symb);
char *str_clean(char const *str);
int ignore_space_and_tabs(int i, char const *str);
int check_unmatched(my_minishell_t *my_minishell, char const *str);
void remove_quote(char **argu);

// gestion de la commande cd
int my_cd(char **all_command, my_minishell_t *my_minishell);
int path_to_home(my_minishell_t *my_minishell);
int path_to_previous(my_minishell_t *my_minishell);
int path_to_back(my_minishell_t *my_minishell);
char **back_from_path(char *str);

// gestion de la commande exit
int my_exit(char **all_command, my_minishell_t *my_minishell);

// gestion de la commande echo
int my_echo(char **all_command, my_minishell_t *my_minishell);

// gestion du builtin which
int my_which(char **all_command, my_minishell_t *my_minishell);

// gestion du builtin where
int my_where(char **all_command, my_minishell_t *my_minishell);

// gestion du builtin whereis
int my_whereis(char **all_command, my_minishell_t *my_minishell);

// gestion du builtin repeat
int my_repeat(char **all_command, my_minishell_t *my_minishell);

// gestion du builtin set
int my_set(char **all_commands, my_minishell_t *my_minishell);

// gestion du builtin unset
int my_unset(char **all_commands, my_minishell_t *my_minishell);
int remove_double_set(variable_t **head, char *name);
void free_struct_set(variable_t *head);
int remove_double_set(variable_t **head, char *name);
int add_var(variable_t **head, char *temp_cmd);
// gestion du builtin unalias
int my_unalias(char **all_command, my_minishell_t *my_minishell);

// gestion du builtin alias
int my_alias(char **all_commands, my_minishell_t *my_minishell);

// gestion du builtin kill
int my_kill(char **all_command, my_minishell_t *my_minishell);

// gere et remplace les alias dans la command line
void handle_alias(my_minishell_t *my_minishell);
void add_node(alias_t **head, char *str, char **all_commands);
int remove_double(alias_t **head, char *name);
void free_struct_alias(alias_t *head);
int handling_error_alias(char *str, char **all, int len_tab);
int check_alias_str(char *str, char **all);
void display_alias(my_minishell_t  *my_minishell, char **all_commands);
int is_builtin(char *command);

// gestion de l'environnement
char **tab_env_from_queue(my_env_t *env);
my_env_t *create_my_env_node(char **tab, int status);
my_env_t *create_my_env(char **env);
int print_my_env(char **all_command, my_minishell_t *my_minishell);
int set_my_env(char **all_command, my_minishell_t *my_minishell);
int unset_my_env(char **all_command, my_minishell_t *my_minishell);
void free_my_env_node(my_env_t *node);

// gestion des pipes
void handle_pipe(my_minishell_t *my_minishell, char *command);

// gestion && et ||
void check_or_and(my_minishell_t *my_minishell, char *command);

// gestion des redirections potentielles
void choose_redirection(my_minishell_t *my_minishell, char *command);
int check_redirection(char *command, my_minishell_t *my_minishell, int redir);
int check_redirection_from(char *command, my_minishell_t *my_minishell);
int check_redirection_to(char *command, my_minishell_t *my_minishell);
int check_double_redirection(char *command, my_minishell_t *my_minishell,
int redir);
int check_double_redirection_from(char *command, my_minishell_t *my_minishell);
int check_double_redirection_to(char *command, my_minishell_t *my_minishell);

// vérification de l'existence d'un fichier
int verify_file_existed_redir_from(char const *file);
int verify_file_existed_redir_to(char const *file);

// gestion de l'historique et des flèches directionnelles
int manage_line_editing(my_minishell_t *my_minishell);

// enable raw mode
void enable_raw_mode(void);

// to know if a command is started by a builtin
int is_builtin(char *command);

// functions to find and replace variables in env
int replace_variables(my_minishell_t *min, int i);
char *find_in_local_var(char *str, my_minishell_t *min);
char *find_in_env(char *str, my_minishell_t *min);

// function to convert a number to a string
void convert_nbr_to_string(int nb, char *str, my_minishell_t *min);

// tableau contenant les tailles de string des différents bultin
static const int BUILTIN_SIZE[] = {
    2,
    3,
    4,
    6,
    8,
    4,
    5,
    7,
    6,
    5,
    7,
    4,
    3,
    5,
    5,
    -1
};

// tableau contenant les string des différents builtin
static const char *BUILTIN_TAB[] = {
    "cd",
    "env",
    "exit",
    "setenv",
    "unsetenv",
    "echo",
    "which",
    "whereis",
    "repeat",
    "alias",
    "unalias",
    "kill",
    "set",
    "unset",
    "where",
    NULL
};

// tableau contenant les fonctions associées aux différents builtin
static const int (*BUILTIN_POINTERS[])(char **, my_minishell_t *) = {
    &my_cd,
    &print_my_env,
    &my_exit,
    &set_my_env,
    &unset_my_env,
    &my_echo,
    &my_which,
    &my_whereis,
    &my_repeat,
    &my_alias,
    &my_unalias,
    &my_kill,
    &my_set,
    &my_unset,
    &my_where,
    NULL
};

// GLOBBINGS

char *run_globbings(char *command);
int check_for_chars(char *match);
int get_array_strlen(char **array);
void fill_with_filenames(char *new_argv, glob_t *results);
int check_for_chars(char *match);
int *check_match(char **argv);
int get_match_len(char **argv, int *matches);
void fill_new_argv(char **argv, int files_nb, char *new_argv, int *matches);
void free_globbings(char **argv, int *matches);

#endif /* !MINISHELL_H */
