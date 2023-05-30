/*
** EPITECH PROJECT, 2022
** B-CPE-101-STG-1-1-myprintf-noe.tritsch
** File description:
** my_printf.h
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>

int my_compute_power_rec(int nb, int p);
int my_nbrlen(int number);
int my_printf(char *str, ...);
int power_g_upp(double number, float point);
int power_g(double number, float point);
int my_put_float_g(double number);
int my_put_float_g_upp(double number);
int power_upp(double number, float point);
int my_put_float_e_upp(double number);
int power(double number, float point);
int my_put_float_e(double number);
int my_put_in_expo(double number, int count);
void expo(int count, double point);
int my_put_expo_g(double number, int count);
int print_zero(int power, long long nb, int six);
int tempo(long temp, int six);
int my_put_float_zero(double number);
int my_put_float(double number);
void my_putchar(char c);
int my_putnbr_base_long(long nb, char const *str, int count);
int shownbr_base_unsigned(unsigned long nbr, int length, char const *base);
int my_putnbr_base_p(unsigned long long nbr, char const *base);
int my_putnbr_base_unsign(unsigned long long nb, char const *str,int count);
int my_putnbr_base(int nb, char const *str);
int my_putnbr_float(long int nb);
int my_putnbr_u(long int nb);
int my_putnbr(int nb);
int my_putstr(const char *str);
int my_strlen(char const *str);
int return_to_pourcent(const char *format, int i);
int put_space(const char *format, int i);

#endif /* !MY_PRINTF_H_ */
