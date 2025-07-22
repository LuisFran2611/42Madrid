SRCS = ./sources/ft_printf.c ./sources/ft_print_int.c ./sources/ft_print_hex.c \
        ./sources/ft_print_char.c ./sources/ft_print_ptr.c ./sources/ft_print_str.c \
        ./sources/ft_print_uns_int.c

OBJS = $(SRCS:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

