CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LDFLAGS	=
LDLIBS	=

SRC	= buffer \
conversion \
error \
flags \
ft_asprintf \
ft_atoi \
ft_bzero \
ft_dprintf \
ft_eprintf \
ft_fprintf \
ft_printf \
ft_snprintf \
ft_sprintf \
ft_strchr \
ft_strlen \
ft_strpbrk \
ft_wstrcpy \
ft_wstrlen \
parse \
print_formated_char \
print_formated_digit \
print_formated_hex \
print_formated_octal \
print_formated_pointer \
print_formated_space \
print_formated_string \
print_formated_unsigned \
print_formated_widechar \
segment

SUFFIX	= .o
NAME	= libftprintf.a

CORR_FILES = ./Makefile ./src

# DEBUG routine
ifeq ($(BUILD), Debug)
	CFLAGS	+= -fsanitize=address -g -O0 -D DEBUG
	SUFFIX	= .debug.o
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

ifeq ($(BUILD), Debug)
	SRC +=
endif

SRC := $(addsuffix .c, $(SRC))

OBJ = $(subst $(SRC_PREFIX), , $(SRC:.c=$(SUFFIX)))
OBJ := $(addprefix $(OBJ_PREFIX), $(OBJ))

.PHONY: all clean fclean re debug correction

all: $(NAME)

debug:
	@$(MAKE) BUILD=Debug all

$(NAME): $(OBJ)
	@echo "making $@"
	@ar rc $@ $^
	@ranlib $(NAME)

$(OBJ_PREFIX)%$(SUFFIX): $(SRC_PREFIX)%.c
	@echo "making $@"
	@mkdir -p $(OBJ_PREFIX)
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	/bin/rm -rf $(OBJ_PREFIX)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

correction_%:
	@echo "\033[32mCopying libftprintf into \033[33m/tmp/$*\033[0m"
	@mkdir -p /tmp/$*/libftprintf
	@rsync -r --copy-links $(CORR_FILES) /tmp/$*/libftprintf
