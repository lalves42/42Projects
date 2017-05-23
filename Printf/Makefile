#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/14 16:10:20 by lalves            #+#    #+#              #
#    Updated: 2016/11/11 17:09:37 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libftprintf.a

CC			=	gcc
RM			=	rm -rfv

CFLAGS		=	-Wall -Wextra -Werror -g -O0 #-fsanitize=address
CPPFLAGS	=	-Iincludes

SRC_PATH	=	srcs/
OBJ_PATH	=	obj/

SRC_NAME1	=	ft_strmaj ft_itoa_base ft_error ft_strlen ft_itoa ft_strdup			\
				ft_strcpy ft_atoi ft_strnew ft_strdel ft_strjoin ft_putchar			\
				ft_memdel ft_strnew_c ft_printf apply_precision apply_width			\
				fonction get_conv ft_putwstr ft_putwchar ft_strcmp ft_putstr		\
				ft_wcharlen ft_wstrlen convert_char convert_percent convert_ptr		\
				convert_signed convert_unsigned convert_str convert_wchar			\
				convert_wstr ft_isdigit ft_putendl ft_bzero							\

SRC_NAME	=	$(addsuffix .c, $(SRC_NAME1))
OBJ_NAME	=	$(addsuffix .o, $(SRC_NAME1))

SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))


.PHONY:		all, clean, fclean, re

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@$(RM) $(OBJ_PATH)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all
