CC=cc
FLAGS=-Wall -Werror -Wextra -g
LIBFT_DIR=libft/
LIBFT=libft.a
SRC_DIR=srcs/
SRCS=$(SRC_DIR)/export.c \
	 $(SRC_DIR)/pwd.c \
	 $(SRC_DIR)/env.c \
	 $(SRC_DIR)/unset.c \
	 $(SRC_DIR)/echo.c \
	 $(SRC_DIR)/cd.c \
	 $(SRC_DIR)/exit.c \
	 $(SRC_DIR)/environement.c \
	 $(SRC_DIR)/shell.c \
	 $(SRC_DIR)/test.c \
	 $(SRC_DIR)/utils.c
OBJS=$(SRCS:.c=.o)
NAME=mini-shell

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) -lft -L$(LIBFT_DIR)

$(LIBFT): $(LIBFT_DIR)
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
