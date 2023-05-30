##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## piscine
##

SRC	=	my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strdup.c	\
		my_is_alpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlowcase.c	\
		my_strncat.c 	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_str_to_word_array.c	\
		my_str_to_word_array_spe.c	\
		my_strupcase.c	\
		my_swap.c	\
		load_file_in_mem.c	\
		load_2d_arr_from_file.c	\
		find_biggest_line.c	\
		find_cols.c	\
		count_symb.c	\
		create_my_binary.c	\
		my_node.c	\
		lowest_in_int_tab.c	\
		max_in_int_tab.c	\
		copy_tab.c	\
		strdup.c	\
		create_my_priority_queue.c	\
		my_printf/my/my_printf.c	\
		my_printf/flags/flag_b.c	\
		my_printf/flags/flag_c.c	\
		my_printf/flags/flag_d.c	\
		my_printf/flags/flag_e_e_upp.c	\
		my_printf/flags/flag_g_g_upp.c	\
		my_printf/flags/flag_i.c	\
		my_printf/flags/flag_o.c 	\
		my_printf/flags/flag_p.c 	\
		my_printf/flags/flag_percent.c	\
		my_printf/flags/flag_s.c	\
		my_printf/flags/flag_s_uppercase.c	\
		my_printf/flags/flag_x.c	\
		my_printf/flags/flag_x_uppercase.c	\
		my_printf/flags/flag_f_f_upp.c	\
		my_printf/flags/flag_u.c	\
		my_printf/flags/flag_n.c	\
		my_printf/my/my_putnbr.c	\
		my_printf/my/my_putnbr_u.c	\
		my_printf/my/my_putchar.c	\
		my_printf/my/my_putnbr_base.c	\
		my_printf/my/my_putnbr_base_long.c	\
		my_printf/my/my_putnbr_float.c	\
		my_printf/my/my_putstr.c	\
		my_printf/my/my_strlen.c	\
		my_printf/my/my_put_float.c	\
		my_printf/my/my_put_float_e.c	\
		my_printf/my/my_put_float_g.c	\
		my_printf/my/my_put_float_e_upp.c	\
		my_printf/my/my_compute_power_rec.c	\
		my_printf/my/my_nbrlen.c	\
		my_printf/my/my_put_expo_g.c	\
		my_printf/my/my_putnbr_base_unsign.c	\
		my_printf/my/specifier.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
