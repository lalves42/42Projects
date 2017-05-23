#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/14 16:10:20 by lalves            #+#    #+#              #
#    Updated: 2016/11/22 00:48:45 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	push_swap
CHECKER			=	checker

CC				=	gcc
MAKE			=	make
RM				=	rm -rfv

CFLAGS			=	-Wall -Wextra -Werror
CPPFLAGS		=	-Ichecker_dir/inc -Ipush_swap_dir/inc -Ilibft/inc/
LDFLAGS			=	-Llibft
LDLIBS			=	-lft
LIB				=	libft/libft.a

SRC_CH_PATH		=	./checker_dir/src/
SRC_PS_PATH		=	./push_swap_dir/src/
OBJ_CH_PATH		=	./checker_dir/obj/
OBJ_PS_PATH		=	./push_swap_dir/obj/

SRC_CH_NAME		=	apply_cmd.c apply_cmd2.c apply_cmd3.c flags.c check_error.c				\
					display_error.c free_stack.c get_string.c get_tab.c main.c				\

SRC_PS_NAME		=	apply_cmd.c apply_cmd2.c apply_cmd3.c bubble_sort.c check_error.c		\
					display_error.c free_stack.c get_string.c get_tab.c main.c				\
					quick_sort.c sort_tab.c													\

OBJ_CH_NAME		=	$(SRC_CH_NAME:.c=.o)
OBJ_PS_NAME		=	$(SRC_PS_NAME:.c=.o)

OBJ_CH			=	$(addprefix $(OBJ_CH_PATH), $(OBJ_CH_NAME))
OBJ_PS			=	$(addprefix $(OBJ_PS_PATH), $(OBJ_PS_NAME))


.PHONY:		all, clean, fclean, re


all:		$(NAME) $(CHECKER)

$(NAME):	$(OBJ_PS) $(LIB)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ_PS) -o $(NAME)

$(OBJ_PS_PATH)%.o: $(SRC_PS_PATH)%.c
	@mkdir -p $(OBJ_PS_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(CHECKER):	$(OBJ_CH) $(LIB)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ_CH) -o $(CHECKER)

$(OBJ_CH_PATH)%.o: $(SRC_CH_PATH)%.c
	@mkdir -p $(OBJ_CH_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB):
	$(MAKE) -C libft

clean:
	@$(RM) $(OBJ_CH_PATH)
	@$(RM) $(OBJ_PS_PATH)
	@$(MAKE) -C libft clean

fclean:		clean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)
	@$(MAKE) -C libft fclean

re:			fclean all