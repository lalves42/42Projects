#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/09 13:58:20 by lalves            #+#    #+#              #
#    Updated: 2016/05/03 16:12:34 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SRC_NAME2	=	memset bzero memcpy memccpy memmove memchr memcmp			\
				strlen strdup strcpy strncpy strcat strncat strlcat			\
				strchr strrchr strstr strnstr strcmp strncmp atoi			\
				isalpha isdigit isalnum isascii isprint toupper tolower		\
				memalloc memdel strnew strdel strclr striter striteri		\
				strmap strmapi strequ strnequ strsub strjoin strtrim		\
				strsplit itoa putchar putstr putendl putnbr putchar_fd		\
				putstr_fd putendl_fd putnbr_fd putmem putmem_fd isspace		\
				lstnew lstdelone lstdel lstadd lstiter lstmap lstsize		\
				lstadd_back abs	putcolor error								\

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
