#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lalves <lalves@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/12 18:45:02 by lalves            #+#    #+#              #
#    Updated: 2017/02/17 19:25:04 by akopera          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

LIBFT_PATH			= ../libft
LIBFTPRINTF_PATH	= ../libftprintf

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -I./includes
LDFLAGS	= -L$(LIBFT_PATH) -L$(LIBFTPRINTF_PATH)
LDLIBS	= -lft -lftprintf

SRC	=	main arguments options errors \
		players champion process registers \
		vm dump cycles run_processes kill convert memory \
		op op_arguments op_value \
		live_op ld_op st_op add_op sub_op and_op or_op xor_op \
		zjmp_op ldi_op sti_op fork_op lld_op lldi_op lfork_op aff_op

CORR_FILES = ./Makefile ./src ./includes

ifeq ($(BUILD), Bonus)
	CFLAGS	+= -D BONUS
	BONUS_SRC	= curses colors window wprint \
				draw panels panel_memory panel_infos panel_help \
				memory bytes
	BONUS_SRC := $(addprefix bonus/, $(BONUS_SRC))
	SRC		+= $(BONUS_SRC)
	LDLIBS	+= -lncurses
endif

# DEBUG routine
ifeq ($(BUILD), Debug)
	CFLAGS	+= -g -O0 -D DEBUG
	SUFFIX	= .debug.o
	NAME	= corewar.debug
	SRC		+=
else
	SUFFIX	= .o
	NAME	= corewar
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

bonus:
	@mkdir -p $(OBJ_PREFIX)bonus
	@$(MAKE) BUILD=Bonus all

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
