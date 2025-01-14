# Nom de la bibliothèque
NAME = libft.a

# Compilateur et options
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Commandes
AR = ar rcs
RM = rm -f

# Sources obligatoires
SRCS = 	is/ft_isalpha.c \
		is/ft_isdigit.c \
		is/ft_isalnum.c \
		is/ft_isascii.c \
		is/ft_isprint.c \
       	str/ft_strlen.c \
	   	mem/ft_memset.c \
		malloc/ft_bzero.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
       	str/ft_strlcpy.c \
		str/ft_strlcat.c \
		to/ft_toupper.c \
		to/ft_tolower.c \
		str/ft_strchr.c \
       	str/ft_strrchr.c \
		str/ft_strncmp.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		str/ft_strnstr.c \
       	ascii/ft_atoi.c \
		malloc/ft_calloc.c \
		str/ft_strdup.c \
		str/ft_substr.c \
		str/ft_strjoin.c \
       	str/ft_strtrim.c \
		malloc/ft_split.c \
		ascii/ft_itoa.c \
		str/ft_strmapi.c \
		str/ft_striteri.c \
       	fd/ft_putchar_fd.c \
		fd/ft_putstr_fd.c \
		fd/ft_putendl_fd.c \
		fd/ft_putnbr_fd.c \
		ascii/ft_atol.c \

# Sources bonus
BONUS_SRCS = 	list/ft_lstnew_bonus.c \
				list/ft_lstadd_front_bonus.c \
				list/ft_lstsize_bonus.c \
				list/ft_lstlast_bonus.c \
             	list/ft_lstadd_back_bonus.c \
			 	list/ft_lstdelone_bonus.c \
				list/ft_lstclear_bonus.c \
				list/ft_lstiter_bonus.c \
             	list/ft_lstmap_bonus.c \

# Objets
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Règles
all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re