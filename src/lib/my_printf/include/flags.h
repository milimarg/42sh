/*
** EPITECH PROJECT, 2022
** flags
** File description:
** printf
*/

#ifndef flags_t
    #define flags_t
    #include <stdarg.h>

int flag_s(va_list list, char *format, int i);
int flag_percent(va_list list, char *format, int i);
int flag_c(va_list list, char *format, int i);
int flag_i(va_list list, char *format, int i);
int flag_d(va_list list, char *format, int i);
int flag_e(va_list list, char *format, int i);
int flag_e_uppercase(va_list list, char *format, int i);
int flag_g(va_list list, char *format, int i);
int flag_g_uppercase(va_list list, char *format, int i);
int flag_x(va_list list, char *format, int i);
int flag_o(va_list list, char *format, int i);
int flag_p(va_list list, char *format, int i);
int flag_hexa_uppercase(va_list list, char *format, int i);
int flag_b(va_list list, char *format, int i);
int flag_f(va_list list, char *format, int i);
int flag_u(va_list list, char *format, int i);
int flag_f_uppercase(va_list list, char *format, int i);
int flag_s_uppercase(va_list list, char *format, int i);
void flag_n(va_list list, int count);

#endif /* !flags */
