# **************************************************************************** #
#                                   VARIABLES                                  #
# **************************************************************************** #

# Compilador y banderas
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f

# Ejecutable final
NAME = so_long

# Directorios
LIBFT_DIR = ./libft
PRINTF_DIR = ./libft/ft_printf
GNL_DIR = ./libft/get_next_line
MLX_DIR = ./minilibx-linux

# Archivos de las bibliotecas
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
GNL_SRCS = $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11

# Archivos principales
SRCS = ./so_long.c ./inicialice.c ./map_check.c ./animate.c ./mov.c ./free_recourses.c ./sprites.c# Agrega los archivos principales de tu juego aquí
OBJS = $(SRCS:.c=.o)

# **************************************************************************** #
#                                   REGLAS                                     #
# **************************************************************************** #

# Regla principal
all: $(LIBFT) $(PRINTF) $(MLX) $(NAME)

# Compilar la librería libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compilar la librería ft_printf
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

# Compilar la biblioteca MiniLibX
$(MLX):
	$(MAKE) -C $(MLX_DIR)

# Compilar el ejecutable principal
$(NAME): $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

# Limpieza de archivos objeto
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(PRINTF_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) $(OBJS) $(GNL_OBJS)

# Limpieza completa
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

# Regenerar todo desde cero
re: fclean all

.PHONY: all clean fclean re
