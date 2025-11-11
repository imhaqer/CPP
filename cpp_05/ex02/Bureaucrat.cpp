#include "Bureaucrat.hpp"
#include "Form.hpp"


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name_("Default"), grade_(MIN_GRADE){}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(std::string const name, unsigned int grade): name_(name) {

	if (grade < MIN_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MAX_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade_ = grade;
	std::cout << "Bureaucrat named " << name << " created with grade " << grade << std::endl;
}



Bureaucrat::Bureaucrat(const Bureaucrat &cpy): name_(cpy.getName()), grade_(cpy.getGrade()) {
	std::cout << "Bureaucrat named " << cpy.getName() << " with grade ";
	std::cout << cpy.getGrade() << " copied" << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

std::string	Bureaucrat::getName() const {
	return (this->name_);
}

unsigned  int	Bureaucrat::getGrade() const {
	return (this->grade_);
}

void	Bureaucrat::incrementGrade() {
	if (this->grade_ > 1)
		this->grade_--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if (this->grade_ < 150)
		this->grade_++;
	else
		throw Bureaucrat::GradeTooLowException();
}


const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ((char *)"Invalid grade: grade too high. Grade must be between 1 and 150");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ((char *)"Invalid grade: grade too low. Grade must be between 1 and 150");
}


// New method to sign a form
void Bureaucrat::signForm(Form &form) const {
    try {
        form.beSigned(*this);
        std::cout << name_ << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name_ << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}