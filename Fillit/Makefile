#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/29 02:32:20 by lalves            #+#    #+#              #
#    Updated: 2016/05/03 16:55:20 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME			=	fillit

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

SRC_PATH		=	./src/

OBJ_PATH		=	./obj/

SRC_NAME		=	main.c					\
					read_and_check.c		\
					find.c					\
					find_bis.c				\
					grid.c					\
					solve.c					\
					convert.c				\

OBJ_NAME		=	$(SRC_NAME:.c=.o)

SRC				=	$(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

LIB_PATH		=	-LLibft

LIB				=	-lft

LIBRARY			=	./Libft/libft.a

INC				=	-ILibft

all:			$(NAME)

$(NAME):		$(OBJ) $(LIBRARY)
	$(CC) $(LIB_PATH) $(LIB) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(LIBRARY):
	make -C ./Libft

clean:
	@rm -fv $(OBJ)
	@rm -rfv $(OBJ_PATH)
	@make -C ./Libft clean

fclean:			clean
	@rm -fv $(NAME)
	@make -C ./Libft fclean

re:				fclean all