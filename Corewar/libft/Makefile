

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
LDFLAGS	=
LDLIBS	=

SRC	= ft_atoi \
ft_atoimax \
ft_bzero \
ft_dl_lstback \
ft_dl_lstclear \
ft_dl_lstfront \
ft_dl_lstiter \
ft_dl_lstmap \
ft_dl_lstnew \
ft_dl_lstpopback \
ft_dl_lstpopfront \
ft_dl_lstpushback \
ft_dl_lstpushfront \
ft_dl_lstsize \
ft_imaxtoa \
ft_isalnum \
ft_isalpha \
ft_isascii \
ft_isdigit \
ft_islower \
ft_isprint \
ft_isspace \
ft_isupper \
ft_itoa \
ft_itoa_base \
ft_lstadd \
ft_lstdel \
ft_lstdelone \
ft_lstgetat \
ft_lstiter \
ft_lstmap \
ft_lstnew \
ft_lstsize \
ft_lstsort \
ft_memalloc \
ft_memccpy \
ft_memchr \
ft_memcmp \
ft_memcpy \
ft_memdel \
ft_memmove \
ft_memset \
ft_pow \
ft_putaddr \
ft_putchar \
ft_putchar_fd \
ft_putendl \
ft_putendl_fd \
ft_putnbr \
ft_putnbr_fd \
ft_putstr \
ft_putstr_fd \
ft_queueback \
ft_queuenew \
ft_queuepop \
ft_queuepush \
ft_queuesize \
ft_stacknew \
ft_stackpop \
ft_stackpush \
ft_stacksize \
ft_strcat \
ft_strchr \
ft_strclr \
ft_strcmp \
ft_strconcat \
ft_strcpy \
ft_strdel \
ft_strdup \
ft_strequ \
ft_striter \
ft_striteri \
ft_strjoin \
ft_strlcat \
ft_strlen \
ft_strmap \
ft_strmapi \
ft_strncat \
ft_strncmp \
ft_strnconcat \
ft_strncpy \
ft_strnequ \
ft_strnew \
ft_strnjoin \
ft_strnstr \
ft_strpbrk \
ft_strprepend \
ft_strrchr \
ft_strsplit \
ft_strstr \
ft_strsub \
ft_strtrim \
ft_tolower \
ft_toupper \
ft_uitoa

SUFFIX	= .o
NAME	= libft.a

CORR_FILES = ./Makefile ./src

# DEBUG routine
ifeq ($(BUILD), Debug)
	CFLAGS	+= -fsanitize=address -g -O0 -D DEBUG
	SUFFIX	= .debug.o
	SRC += debug/ft_debug_error_free debug/ft_debug_error_param
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

.PHONY: all re debug bonus clean fclean correction

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
	@mkdir -p $(OBJ_PREFIX)debug/
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	/bin/rm -rf $(OBJ_PREFIX)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

correction_%:
	@echo "\033[32mCopying libft into \033[33m/tmp/$*\033[0m"
	@mkdir -p /tmp/$*/libft
	@rsync -r --copy-links $(CORR_FILES) /tmp/$*/libft
