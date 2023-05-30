##
## EPITECH PROJECT, 2023
## minishell
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/free/free_my_tab.c	\
		src/env/create_my_env.c	\
		src/env/create_my_env_node.c	\
		src/env/print_my_env.c	\
		src/loop_minishell.c	\
		src/minishell_ope.c	\
		src/utilities/my_strcat_minishell.c	\
		src/utilities/switch_my_exit.c	\
		src/free/free_my_minishell.c	\
		src/utilities/print_my_emplacement.c	\
		src/utilities/not_only_space.c	 \
		src/utilities/is_builtin.c	\
		src/init/handle_my_signals.c	\
		src/env/tab_env_from_queue.c	\
		src/builtin/my_cd.c	\
		src/builtin/my_cd_two.c	\
		src/env/set_my_env.c	\
		src/env/unset_my_env.c	\
		src/free/free_my_env_node.c	\
		src/utilities/command_not_found.c	\
		src/builtin/my_exit.c	\
		src/builtin/my_echo.c	\
		src/init/create_my_minishell.c	\
		src/utilities/str_clean.c	\
		src/init/initialize_pwd.c	\
		src/utilities/split_my_command_line.c	\
		src/separators/check_redirection.c	\
		src/separators/check_redirection_from.c	\
		src/separators/check_redirection_to.c	\
		src/separators/check_double_redirection.c	\
		src/separators/check_double_redirection_from.c	\
		src/separators/check_double_redirection_to.c	\
		src/separators/check_or_and.c	\
		src/utilities/cut_my_string_by_word.c	\
		src/utilities/cut_my_string_by_two_words.c	\
		src/utilities/strcmp_word.c	\
		src/utilities/perfect_malloc.c	\
		src/utilities/perfect_malloc_two_words.c	\
		src/utilities/separate_args.c	\
		src/utilities/count_my_words.c	\
		src/utilities/separate_args_spe.c	\
		src/utilities/count_my_spe.c	\
		src/utilities/quote_check.c	\
		src/utilities/ignore_space_and_tabs.c	\
		src/separators/handle_pipe.c	\
		src/separators/choose_redirection.c	\
		src/separators/check_unmatched.c	\
		src/history/history.c	\
		src/line_editing/arrows_ctrl.c	\
		src/line_editing/arrows.c	\
		src/line_editing/delete.c	\
		src/line_editing/end_of_file.c	\
		src/line_editing/line_editing.c	\
		src/line_editing/write_char.c	\
		src/line_editing/write_end.c	\
		src/line_editing/autocompletion.c	\
		src/line_editing/autocomplete_input.c	\
		src/builtin/my_which.c	\
		src/builtin/my_whereis.c	\
		src/builtin/my_whereis_two.c	\
		src/builtin/my_repeat.c	\
		src/builtin/my_alias.c	\
		src/builtin/my_alias_two.c	\
		src/builtin/my_alias_three.c	\
		src/builtin/my_unalias.c \
		src/builtin/my_kill.c \
		src/free/free_struct_alias.c	\
		src/globbings/run_globbing.c \
		src/globbings/tools.c \
		src/globbings/check_for_match.c \
		src/globbings/argv.c \
		src/globbings/free.c	\
		src/builtin/my_set.c	\
		src/builtin/my_set_two.c	\
		src/builtin/my_unset.c	\
		src/free/free_struct_set.c	\
		src/builtin/my_where.c	\
		src/env/replace_variables.c	\
		src/env/find_variables.c	\
		src/utilities/convert_nbr_to_string.c

BUILD	=	build

OBJ	=	$(patsubst src/%.c, $(BUILD)/%.o, $(SRC))

NAME	=	42sh

DEBUG	=	-g

LIBS	=	src/libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C src/lib/
	gcc -o $(NAME) $(OBJ) $(LIBS) $(DEBUG)

$(BUILD)/%.o: src/%.c
	mkdir -p $(dir $@)
	gcc -c $< -o $@ $(DEBUG)

clean:
	make -C src/lib/ clean
	rm -rf $(BUILD)

fclean:	clean
	make -C src/lib/ fclean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
