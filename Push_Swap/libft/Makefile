#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/14 16:10:20 by lalves            #+#    #+#              #
#    Updated: 2016/10/14 20:10:31 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

CC			=	gcc
RM			=	rm -rfv

CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-Iinc

SRC_PATH	=	src/
OBJ_PATH	=	obj/

SRC_NAME1	=	memset bzero memcpy memccpy memmove memchr memcmp           \
                strlen strdup strcpy strncpy strcat strncat strlcat         \
                strchr strrchr strstr strnstr strcmp strncmp atoi           \
                isalpha isdigit isalnum isascii isprint toupper tolower     \
                memalloc memdel strnew strdel strclr striter striteri       \
                strmap strmapi strequ strnequ strsub strjoin strtrim        \
                strsplit itoa putchar putstr putendl putnbr putchar_fd      \
                putstr_fd putendl_fd putnbr_fd putmem putmem_fd isspace     \
                lstnew lstdelone lstdel lstadd lstiter lstmap lstsize       \
                lstadd_back abs putcolor get_next_line itoa_base error      \
                strmin strmaj strrev itoa_base_printf printf putwstr		\
				putwchar wcharlen wstrlen get_flags get_conv apply_width	\
				apply_precision strcpy_printf convert_char convert_str		\
				convert_wchar convert_wstr convert_ptr convert_percent		\
				convert_signed convert_unsigned strnew_c					\

SRC_NAME	=	$(addprefix ft_, $(addsuffix .c, $(SRC_NAME1)))
OBJ_NAME	=	$(SRC_NAME:.c=.o)

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