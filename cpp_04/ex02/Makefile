NAME = Animal
CC = c++ 
CFLAGS = -Wall -Werror -Wextra -std=c++11
SRC = srcs/main.cpp srcs/Animal.cpp srcs/Cat.cpp srcs/Dog.cpp srcs/WrongCat.cpp srcs/WrongAnimal.cpp  srcs/Brain.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = include/Animal.hpp  include/Cat.hpp include/Dog.hpp include/WrongCat.hpp include/WrongAnimal.hpp include/Brain.hpp
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