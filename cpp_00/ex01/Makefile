NAME = phonebook
CC = c++ 
CFLAGS = -Wall -Werror -Wextra -std=c++11
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)
HEADERS = Contact.hpp PhoneBook.hpp
INC = -I.

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