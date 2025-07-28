NAME = FragTrap
CC = c++ 
CFLAGS = -Wall -Werror -Wextra -std=c++11
SRC = srcs/main.cpp srcs/ClapTrap.cpp srcs/FragTrap.cpp  srcs/ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = include/ClapTrap.hpp include/FragTrap.hpp include/ScavTrap.hpp
INC = -I include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.PHONY: all clean fclean re