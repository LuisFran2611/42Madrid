CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_calculator.c ft_operations.c ft_putnbr.c
OBJ = $(SRC:.c=.o)
NAME = do-op

# Reglas
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
