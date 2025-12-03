CC=cc
FLAGS=-Werror -Wall -Wextra
SRCS=ft_isalpha.c \
	 ft_isdigit.c \
	 ft_isalnum.c \
	 ft_isascii.c \
	 ft_isprint.c \
	 ft_strlen.c \
	 ft_memset.c \
	 ft_bzero.c \
	 ft_memcpy.c \
	 ft_memmove.c \
	 ft_strlcpy.c \
	 ft_strlcat.c \
	 ft_toupper.c \
	 ft_tolower.c \
	 ft_strchr.c \
	 ft_strrchr.c \
	 ft_strncmp.c \
	 ft_memchr.c \
	 ft_memcmp.c \
	 ft_strnstr.c \
	 ft_atoi.c \
	 ft_calloc.c \
	 ft_strdup.c \
	 ft_substr.c \
	 ft_strjoin.c \
	 ft_strtrim.c \
	 ft_split.c \
	 ft_itoa.c \
	 ft_strmapi.c \
	 ft_striteri.c \
	 ft_putchar_fd.c \
	 ft_putstr_fd.c \
	 ft_putendl_fd.c \
	 ft_putnbr_fd.c \
	 ft_write.c \
	 ft_realloc.c \
	 ft_doublelen.c \
	 ft_double_write.c \
	 ft_get_row_id.c \
	 ft_replace_row.c \
	 ft_delete_row.c \
	 ft_add_row.c \
	 ft_doubledup.c \
	 ft_double_free.c \
	 ft_double_realloc.c
OBJS=$(SRCS:.c=.o)
NAME=libft.a
HEADER=libft.h
SRCS_BONUS=ft_lstnew_bonus.c \
		   ft_lstadd_front_bonus.c \
		   ft_lstsize_bonus.c \
		   ft_lstlast_bonus.c \
		   ft_lstadd_back_bonus.c \
		   ft_lstdelone_bonus.c \
		   ft_lstclear_bonus.c \
		   ft_lstiter_bonus.c \
		   ft_lstmap_bonus.c
OBJ_BONUS=$(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJS) $(OBJ_BONUS) $(HEADER)
	ar rcs $(NAME) $(OBJS) $(OBJ_BONUS)

$(NAME): $(OBJS) $(HEADER)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) $^ -c -o $@

fclean:
	rm -f $(OBJS) $(OBJ_BONUS) $(NAME)

clean:
	rm -f $(OBJS) $(OBJ_BONUS)

re: clean all
