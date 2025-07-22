# ----------------------------- #
#          EXECUTABLE           #
# ----------------------------- #
NAME = cub3D

# ----------------------------- #
#           COMPILER            #
# ----------------------------- #
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
# For macOS, we need to link against OpenGL and AppKit frameworks
LDFLAGS = -L./lib/libft -lft -L./lib/libft/ft_printf -lftprintf -L./minilibx -lmlx -framework OpenGL -framework AppKit -lm -fsanitize=address

# ----------------------------- #
#           DIRECTORIES         #
# ----------------------------- #
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = lib/libft
MLX_DIR = minilibx
LIBFTPRINTF_DIR = lib/libft/ft_printf

# ----------------------------- #
#             FILES             #
# ----------------------------- #
# Find all .c files in src directory and its subdirectories
SRCS = $(shell find $(SRC_DIR) -name "*.c")

# Replace the .c extension with .o and put them in the obj directory
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# ----------------------------- #
#            COMMANDS           #
# ----------------------------- #
RM = rm -f

# ----------------------------- #
#             RULES             #
# ----------------------------- #
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(LIBFTPRINTF_DIR)/libftprintf.a
	@$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "cub3D compiled!"

# Rule to compile .c files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I./include -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

# Rule for libft
$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

# Rule for libftprintf
$(LIBFTPRINTF_DIR)/libftprintf.a:
	@make -C $(LIBFTPRINTF_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBFTPRINTF_DIR) clean
	@$(RM) -r $(OBJ_DIR)
	@echo "Object files cleaned."

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LIBFTPRINTF_DIR) fclean
	@$(RM) $(NAME)
	@echo "Full clean complete."

re: fclean all

.PHONY: all clean fclean re