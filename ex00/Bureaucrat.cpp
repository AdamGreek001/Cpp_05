#include "Bureaucrat.hpp"

// Static member initialization
const int Bureaucrat::_highestGrade = 1;
const int Bureaucrat::_lowestGrade = 150;

// Orthodox Canonical Form
Bureaucrat::Bureaucrat() : _name("Unnamed_Bureaucrat"), _grade(150) 
{
	std::cout << "[Bureaucrat] Creating default bureaucrat with lowest grade" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) 
{
	if (grade < _highestGrade)
		throw GradeTooHighException();
	if (grade > _lowestGrade)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "[Bureaucrat] " << _name << " hired at grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) 
{
	std::cout << "[Bureaucrat] Cloning " << _name << " (grade: " << _grade << ")" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) 
{
	if (this != &other) {
		_grade = other._grade;
		std::cout << "[Bureaucrat] Transferring grade " << _grade << " to " << _name << std::endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "[Bureaucrat] " << _name << " retired from grade " << _grade << std::endl;
}

// Getters
const std::string& Bureaucrat::getName() const 
{
	return _name;
}

int Bureaucrat::getGrade() const 
{
	return _grade;
}

// Grade management
void Bureaucrat::incrementGrade() 
{
	if (_grade <= _highestGrade)
		throw GradeTooHighException();
	_grade--;
	std::cout << "[Promotion] " << _name << " promoted to grade " << _grade << std::endl;
}

void Bureaucrat::decrementGrade() 
{
	if (_grade >= _lowestGrade)
		throw GradeTooLowException();
	_grade++;
	std::cout << "[Demotion] " << _name << " demoted to grade " << _grade << std::endl;
}

// Exception implementations
const char* Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "ERROR: Grade exceeds maximum level (cannot be higher than 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "ERROR: Grade below minimum level (cannot be lower than 150)";
}

// Overload insertion operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) 
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}
