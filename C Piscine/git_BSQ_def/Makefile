# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmedrano <mmedrano@student.42madrid.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 15:32:22 by mmedrano          #+#    #+#              #
#    Updated: 2024/08/28 10:33:48 by lsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
SRCS = $(SRC_DIR)/read_stdin.c $(SRC_DIR)/bsq.c $(SRC_DIR)/create_map.c $(SRC_DIR)/mem_allocation.c $(SRC_DIR)/process_map.c $(SRC_DIR)/solver.c $(SRC_DIR)/validate_map.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
