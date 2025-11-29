CC=cc
FLAGS=-Wall -Werror -Wextra -g
SRCS=ft_write.c ft_realloc.c ft_strdup.c ft_split.c ft_strnstr.c ft_strlen.c ft_memcpy.c ft_strchr.c export.c pwd.c env.c test.c environement.c unset.c
OBJS=$(SRCS:.c=.o)
NAME=mini-shell

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
