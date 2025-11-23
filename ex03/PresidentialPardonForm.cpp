#include "PresidentialPardonForm.hpp"

// Orthodox Canonical Form
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm parametric constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Execute action
void PresidentialPardonForm::executeAction() const {
	std::cout << "[PRESIDENTIAL DECREE]" << std::endl;
	std::cout << "By the authority vested in Zaphod Beeblebrox, President of the Galaxy," << std::endl;
	std::cout << _target << " is hereby granted full and unconditional pardon." << std::endl;
	std::cout << "[PARDON GRANTED - All charges dismissed]" << std::endl;
}
