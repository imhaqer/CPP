#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor
Form::Form() 
	: name_("Default Form"), formSigned_(false), gradeToSign_(150), gradeToExecute_(150) {}

// Parameterized Constructor
Form::Form(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	: name_(name), formSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &cpy)
	: name_(cpy.name_), formSigned_(cpy.formSigned_),
	  gradeToSign_(cpy.gradeToSign_), gradeToExecute_(cpy.gradeToExecute_) {}

// Assignment operator
Form &Form::operator=(const Form &src) {
	if (this != &src)
		this->formSigned_ = src.formSigned_;
	return *this;
}

// Destructor
Form::~Form() {}

// Getters
const std::string &Form::getName() const {
	return name_;
}

bool Form::isSigned() const {
	return formSigned_;
}

unsigned int Form::getGradeToSign() const {
	return gradeToSign_;
}

unsigned int Form::getGradeToExecute() const {
	return gradeToExecute_;
}

// beSigned()
void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > gradeToSign_)
		throw GradeTooLowException();
	formSigned_ = true;
}

// Exceptions
const char* Form::GradeTooHighException::what() const throw() {
	return "Form: Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form: Grade too low!";
}

// << operator
std::ostream& operator<<(std::ostream &os, const Form &form) {
	os << "Form \"" << form.getName() << "\", signed: " << std::boolalpha << form.isSigned()
	   << ", grade required to sign: " << form.getGradeToSign()
	   << ", grade required to execute: " << form.getGradeToExecute();
	return os;
}

