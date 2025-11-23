#include "Form.hpp"

// Static member initialization
const int Form::_highestGrade = 1;
const int Form::_lowestGrade = 150;

// Orthodox Canonical Form
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	std::cout << "Form parametric constructor called" << std::endl;
	if (gradeToSign < _highestGrade || gradeToExecute < _highestGrade)
		throw GradeTooHighException();
	if (gradeToSign > _lowestGrade || gradeToExecute > _lowestGrade)
		throw GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name), _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other) {
		_isSigned = other._isSigned;
		// _name, _gradeToSign, and _gradeToExecute are const
	}
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

// Getters
const std::string& Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

// Member functions
void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

// Exception implementations
const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade requirement exceeds valid range";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Bureaucrat grade insufficient for this operation";
}

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "[Form] '" << form.getName() << "' [Status: " 
	    << (form.isSigned() ? "SIGNED" : "UNSIGNED")
	    << "] [Sign Grade: " << form.getGradeToSign()
	    << "] [Exec Grade: " << form.getGradeToExecute() << "]";
	return out;
}
