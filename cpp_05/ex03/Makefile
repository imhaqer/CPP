NAME = bureaucrat
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
SRC = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
      RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp
HEADERS = Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
          RobotomyRequestForm.hpp PresidentialPardonForm.hpp Intern.hpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
