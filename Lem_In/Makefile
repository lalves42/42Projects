#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/14 16:10:20 by lalves            #+#    #+#              #
#    Updated: 2016/11/16 17:20:05 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	lem-in

CC			=	gcc
MAKE		=	make
RM			=	rm -rfv

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-Iinc -ILibft/inc
LDFLAGS		=	-LLibft
LDLIBS		=	-lft
LIB			=	Libft/libft.a

SRC_PATH	=	src/
OBJ_PATH	=	obj/

SRC_NAME	=	main.c error.c parsing.c solve.c print_solve.c \
				check_line.c check_link.c save_link.c check_room.c

OBJ_NAME	=	$(SRC_NAME:.c=.o)

SRC			=	$(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))


.PHONY:		all, clean, fclean, re


all:		$(NAME)

$(NAME):	$(OBJ) $(LIB)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

$(LIB):
	$(MAKE) -C Libft

clean:
	@$(RM) $(OBJ_PATH)
	@$(MAKE) -C Libft clean

fclean:		clean
	@$(RM) $(NAME)
	@$(MAKE) -C Libft fclean

re:			fclean all