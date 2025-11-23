#include "AForm.hpp"

// Static member initialization
const int AForm::_highestGrade = 1;
const int AForm::_lowestGrade = 150;

// Orthodox Canonical Form
AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "AForm parametric constructor called" << std::endl;
	if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

// Getters
const std::string& AForm::getName() const {
	return _name;
}

bool AForm::isSigned() const {
	return _isSigned;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

// Member functions
void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const {
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

// Exception implementations
const char* AForm::GradeTooHighException::what() const throw() {
	return "Form grade requirement exceeds valid range";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade insufficient for this operation";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "Cannot execute: form requires signature first";
}

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "[Form] '" << form.getName() << "' [Status: " 
	    << (form.isSigned() ? "SIGNED" : "UNSIGNED")
	    << "] [Sign Grade: " << form.getGradeToSign()
	    << "] [Exec Grade: " << form.getGradeToExecute() << "]";
	return out;
}
