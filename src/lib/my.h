/*
** EPITECH PROJECT, 2022
** my
** File description:
** piscine
*/

#ifndef LIB
    #define LIB
    #include "my_printf/include/my_printf.h"
    #include <fcntl.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <ncurses.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <errno.h>

typedef struct node_s {
    int occurence;
    char symb;
    int total;
    float pourcent;
    char *binary;
    struct node_s* left;
    struct node_s* right;
}node_t;

typedef struct queue_s {
    node_t *node;
    struct queue_s *next;
}queue_t;

/**
 * @brief Try to find a word in a string
 * @param haystack String you want to test
 * @param needle Word you want to find in str
 * @return If success return address of the first letter
**/
char *my_strstr(char *haystack, char const *needle);
/**
 * @brief Say if the nb is Negative or Positive
 * @param nb number you want to test
**/
void my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array_spe(char *str, char spe);
int my_getnbr(char const *str);
int my_is_alpha(char const symb);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_showstr(char const *str);
char *my_strdup(char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *load_file_in_mem(char const *filepath);
char **load_2d_arr_from_file(char *map, int nb_rows, int nb_cols, int header);
int find_cols(char *buff);
int find_biggest_line(char *buff);
int *count_symb(char *buff);
int total_occurency(int *symb_tab);
int *lowest_in_int_tab(int *symb_tab);
int max_in_int_tab(int *symb_tab);
char **copy_tab(char **tab);
char *my_strdup(char const *src);
node_t* my_node(int data, char symb, int total);
queue_t *create_a_queue_node(int data, int symb, int total);
queue_t *create_my_priority_queue(int *symb_tab, int total);
node_t *create_my_binary_tree(queue_t *queue, int total);

#endif
