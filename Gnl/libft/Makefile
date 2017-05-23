#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 13:58:20 by lalves            #+#    #+#              #
#    Updated: 2016/05/05 02:03:29 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SRC_NAME2	=	strsub		\
				strdup		\
				strjoin		\
				strlen		\
				strcpy		\
				strdel		\
				memdel		\

SRC_NAME1	=	$(addprefix ft_, $(SRC_NAME2))

SRC_NAME	=	$(addsuffix .c, $(SRC_NAME1))

OBJ_NAME	=	$(addsuffix .o, $(SRC_NAME1))

all:	$(NAME)

$(NAME):
	@$(CC) -c $(SRC_NAME)
	@ar rc $(NAME) $(OBJ_NAME)
	ranlib $(NAME)

./%.o: ./%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -fv $(OBJ_NAME)

fclean:	clean
	@rm -fv $(NAME)

re:		fclean all
