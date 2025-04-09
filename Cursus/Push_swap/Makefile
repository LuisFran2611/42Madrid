NAME        = push_swap

SRCS        = push_swap.c push.c radix_short.c reverse.c rotate.c swap.c 3_case.c extras.c utils.c spc_cases.c frees.c
OBJS        = $(SRCS:.c=.o)

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
INCLUDES    = -I. -Ilibft

LIBFT_DIR   = libft
PRINTF_DIR = ./libft/ft_printf
LIBFT       = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re