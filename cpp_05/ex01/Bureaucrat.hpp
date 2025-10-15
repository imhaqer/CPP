#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define MAX_GRADE 150
#define MIN_GRADE 1

class Form; // Forward declaration

class Bureaucrat {
	private:
		std::string const name_;
		unsigned int 	grade_;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, unsigned int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat	&operator =(const Bureaucrat &src);



		std::string 	getName() const;
		unsigned int 	getGrade() const;
		void 			incrementGrade();
		void 			decrementGrade();

			// New method to sign a form
		void signForm(Form &form) const;
		
		class GradeTooHighException: public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char* what() const throw();
		};
};
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
#endif