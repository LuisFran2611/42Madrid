# Nombre del ejecutable
NAME = megaphone

# Archivos fuente
SRC = megaphone.cpp

# Compilador y flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Regla por defecto
all: $(NAME)

# Regla para compilar
$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(SRC)

# Limpia el ejecutable
clean:
	rm -f $(NAME)

# Limpia y recompila
re: clean all