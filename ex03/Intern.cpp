#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Orthodox Canonical Form
Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

// Helper function to create ShrubberyCreationForm
static AForm* createShrubberyForm(const std::string& target) {
	return new ShrubberyCreationForm(target);
}

// Helper function to create RobotomyRequestForm
static AForm* createRobotomyForm(const std::string& target) {
	return new RobotomyRequestForm(target);
}

// Helper function to create PresidentialPardonForm
static AForm* createPresidentialForm(const std::string& target) {
	return new PresidentialPardonForm(target);
}

// Member function - Using if-else chain approach
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
	AForm* newForm = NULL;
	
	std::cout << "[Intern] Processing request for '" << formName << "' form..." << std::endl;
	
	if (formName == "shrubbery creation") {
		newForm = new ShrubberyCreationForm(target);
		std::cout << "[Intern] Shrubbery form created successfully for target: " << target << std::endl;
	}
	else if (formName == "robotomy request") {
		newForm = new RobotomyRequestForm(target);
		std::cout << "[Intern] Robotomy request form created for subject: " << target << std::endl;
	}
	else if (formName == "presidential pardon") {
		newForm = new PresidentialPardonForm(target);
		std::cout << "[Intern] Presidential pardon form created for: " << target << std::endl;
	}
	else {
		std::cout << "[Intern] ERROR: Unknown form type '" << formName << "'" << std::endl;
		throw FormNotFoundException();
	}
	
	return newForm;
}

// Exception implementation
const char* Intern::FormNotFoundException::what() const throw() {
	return "Form type does not exist in the catalog";
}
