NAME = phonebook
CC = c++ -Wall -Werror -Wextra
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
%.o: %.cpp
	$(CC) -c $< -o $@
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re