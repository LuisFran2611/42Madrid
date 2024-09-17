#!/bin/bash

SRC_FILES="ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c"
OBJ_FILES="ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o"
LIB_NAME="libft.a"

gcc -Wall -Wextra -Werror -c  $SRC_FILES
ar rcs $LIB_NAME $OBJ_FILES
