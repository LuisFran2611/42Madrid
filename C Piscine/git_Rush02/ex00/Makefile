CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = dict_search.c ft_strcmp.c print_dict.c proces_array.c proces_dict.c rush02.c
OBJS = $(SRCS:.c=.o)
TARGET = rush-02
all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
fclean:
	rm -f $(OBJS)
	rm -f $(TARGET)
.PHONY: fclean all

