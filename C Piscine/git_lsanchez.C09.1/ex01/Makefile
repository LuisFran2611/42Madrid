LIB_NAME = libft.a
INC_DIR = includes
SRC_DIR = srcs
SRC_FILES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ_FILES = $(addprefix $(SRC_DIR)/,$(SRC_FILES:.c=.o))
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(INC_DIR)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	@ar rcs $(LIB_NAME) $(OBJ_FILES)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft.h
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(LIB_NAME)

re: fclean all
.PHONY: all clean fclean re
