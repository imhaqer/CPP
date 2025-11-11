#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() 
	: name_("Default Form"), formSigned_(false), gradeToSign_(150), gradeToExecute_(150) {}

AForm::AForm(const std::string &name, unsigned int gradeToSign, unsigned int gradeToExecute)
	: name_(name), formSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &cpy)
	: name_(cpy.name_), formSigned_(cpy.formSigned_),
	  gradeToSign_(cpy.gradeToSign_), gradeToExecute_(cpy.gradeToExecute_) {}

AForm &AForm::operator=(const AForm &src) {
	if (this != &src)
		this->formSigned_ = src.formSigned_;
	return *this;
}

AForm::~AForm() {}

const std::string &AForm::getName() const { return name_; }
bool AForm::isSigned() const { return formSigned_; }
unsigned int AForm::getGradeToSign() const { return gradeToSign_; }
unsigned int AForm::getGradeToExecute() const { return gradeToExecute_; }

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > gradeToSign_)
		throw GradeTooLowException();
	formSigned_ = true;
}

void AForm::execute(const Bureaucrat &executor) const {
	if (!formSigned_)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute_)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form: Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Form: Form not signed!";
}

std::ostream& operator<<(std::ostream &os, const AForm &form) {
	os << "Form \"" << form.getName() << "\", signed: " << std::boolalpha << form.isSigned()
	   << ", grade required to sign: " << form.getGradeToSign()
	   << ", grade required to execute: " << form.getGradeToExecute();
	return os;
}