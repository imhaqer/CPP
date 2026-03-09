#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string name_;
		bool formSigned_;
		const unsigned int gradeToSign_;
		const unsigned int gradeToExecute_;

	public:
		// Constructors and destructor
		AForm();
		AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &src);
		virtual ~AForm();

		// Getters
		const std::string &getName() const;
		bool isSigned() const;
		unsigned int getGradeToSign() const;
		unsigned int getGradeToExecute() const;

		// Member functions
		void beSigned(const Bureaucrat &b);
		void execute(const Bureaucrat &executor) const;

		// Pure virtual function - makes this class abstract
		virtual void executeAction() const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				const char *what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif