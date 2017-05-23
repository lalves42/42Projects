#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 18:45:02 by lalves            #+#    #+#              #
#    Updated: 2017/03/11 17:29:26 by lalves           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBFT_PATH			= ../libft
LIBFTPRINTF_PATH	= ../libftprintf

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I./includes
LDFLAGS	= -L$(LIBFT_PATH) -L$(LIBFTPRINTF_PATH)
LDLIBS	= -lft -lftprintf

SRC	=	main convert2 errors \
		get_next_line codage \
		opcodes parse convert \
		write opcodes2 opcodes3 \
		opcodes4 check split_line \
		check_op check_op2 check_op3 \
		check_op4 check_op5 split_line2 \
		check2 check3 check_labels write_labels

CORR_FILES = ./Makefile ./src ./includes

ifeq ($(BUILD), Bonus)
	CFLAGS	+= -D BONUS
	SRC		+=
endif

# DEBUG routine
ifeq ($(BUILD), Debug)
	CFLAGS	+= -g -O0 -D DEBUG
	SUFFIX	= .debug.o
	NAME	= asm.debug
	SRC		+=
else
	SUFFIX	= .o
	NAME	= asm
endif

# OS flags
ARCH	= $(shell uname -m)
OS		= $(shell uname -s)

ifeq ($(OS), Darwin)
	LDLIBS +=
endif

ifeq ($(OS)_$(ARCH), Linux_x86_64)
	CFLAGS += -D LINUX
	LDLIBS +=
else ifeq ($(OS), Linux)
	CFLAGS += -D LINUX
	LDLIBS +=
endif

SRC_PREFIX = ./src/
OBJ_PREFIX = ./obj/

SRC := $(addsuffix .c, $(SRC))

OBJ = $(subst $(SRC_PREFIX), , $(SRC:.c=$(SUFFIX)))
OBJ := $(addprefix $(OBJ_PREFIX), $(OBJ))

.PHONY: all clean fclean re libft libftprintf debug correction

all: $(NAME)

debug:
	@$(MAKE) BUILD=Debug all

$(NAME): $(OBJ) $(LIBFT_PATH)/libft.a $(LIBFTPRINTF_PATH)/libftprintf.a
	@echo "making $@"
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_PREFIX)%$(SUFFIX): $(SRC_PREFIX)%.c
	@echo "making $<"
	@mkdir -p $(OBJ_PREFIX)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	/bin/rm -rf $(OBJ_PREFIX)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(LIBFTPRINTF_PATH) clean

fclean: clean
	/bin/rm -f $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(LIBFTPRINTF_PATH) fclean

cclean:
	/bin/rm -rf $(OBJ_PREFIX)
	/bin/rm -f $(NAME)

re: fclean all

rre: cclean all


$(LIBFT_PATH)/libft.a: libft

$(LIBFTPRINTF_PATH)/libftprintf.a: libftprintf

libft:
	@echo "making $@"
	@$(MAKE) -C libft BUILD=$(BUILD) -j 8

libftprintf:
	@echo "making $@"
	@$(MAKE) -C libftprintf BUILD=$(BUILD) -j 8

correction_%:
	@echo "\033[32mCopying $* into \033[33m/tmp/\033[0m"
	@mkdir -p /tmp/$*
	@mkdir -p /tmp/$*/includes
	@rsync -r --copy-links $(CORR_FILES) /tmp/$*
	@$(MAKE) -C libft correction_$*
	@$(MAKE) -C libftprintf correction_$*
