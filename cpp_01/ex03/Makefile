NAME = UNNECESSARY_VIOLENCE
CC = c++ 
CFLAGS = -Wall -Werror -Wextra -std=c++11
SRC = srcs/main.cpp srcs/Weapon.cpp srcs/HumanA.cpp srcs/HumanB.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = include/HumanA.hpp include/HumanB.hpp include/Weapon.hpp
INC = -Iinclude

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