NAME = push_swap

LIBFT_DIR = ./libft

CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize="address"

CC = cc

SRCS = push_swap.c \
		push_swap_moves.c \
		push_swap_sort.c \
		push_swap_utils.c \
		push_swap_main_utils.c \
		push_swap_ksort.c \
		push_swap_moves_a.c \
		push_swap_moves_b.c \

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o:%.c
		$(CC) $(CFLAGS) -I$(LIBFT_DIR)/include -I. -c $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all