# Nombre del ejecutable
NAME = pipex

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Archivos del proyecto
SRC = pipex.c free_recoures.c proces_files.c process.c error.c ft_split_quote.c ft_split_quote_utils.c
OBJ = $(SRC:.c=.o)

# Archivos de la libft
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Incluye los headers de la libft
INCLUDES = -I $(LIBFT_DIR)

# Regla para compilar el proyecto
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

# Compila la libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Limpieza de los archivos objeto del proyecto
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# Limpieza de todos los archivos generados
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Reconstrucción completa del proyecto
re: fclean all

# Regla para depuración (opcional)
debug: CFLAGS += -g -fsanitize=address
debug: re
.PHONY : all clean fclean re debug
