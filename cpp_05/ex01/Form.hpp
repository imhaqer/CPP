#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // Forward declaration

class Form {
	private:
		const std::string name_;
		bool formSigned_;
		const unsigned int gradeToSign_;
		const unsigned int gradeToExecute_;

	public:
		// Constructors and destructor
		Form();
		Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
		Form(const Form &cpy);
		Form &operator=(const Form &src);
		~Form();

		// Getters
		const std::string &getName() const;
		bool isSigned() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;

		// Member function
		void beSigned(const Bureaucrat &b);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};
};

// Overload <<
std::ostream& operator<<(std::ostream &os, const Form &form);

#endif
