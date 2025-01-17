NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# Paths to libraries
LIBFT_PATH = utils/libft
PRINTF_PATH = utils/ftprintf
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

# Source files
SRCS = 	main.c \
		srcs/parsing/core.c \
		srcs/init/core.c \
		srcs/base/push.c \
		srcs/base/swap.c \
		srcs/base/rotate.c \
		srcs/base/reverse.c \
		srcs/sort/core.c

OBJS = $(SRCS:.c=.o)

# Main target
all: $(NAME)

# Build libraries first, then the main program
$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(OBJS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(NAME)

# Rule to build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Rule to build printf
$(PRINTF):
	$(MAKE) -C $(PRINTF_PATH)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(PRINTF_PATH) clean

# Clean everything
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(MAKE) -C $(PRINTF_PATH) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re