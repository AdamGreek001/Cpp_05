#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

// Orthodox Canonical Form
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm parametric constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Execute action
void RobotomyRequestForm::executeAction() const {
	std::cout << "[ROBOTOMY INITIATED]" << std::endl;
	std::cout << ">>> Bzzzzt! Whirrrrr! Clank-clank-clank! <<<" << std::endl;
	std::cout << ">>> Mechanical drilling sounds intensify... <<<" << std::endl;
	
	// Use static counter combined with time for variety
	static unsigned int counter = 0;
	counter++;
	
	if ((std::time(0) + counter) % 2 == 0) {
		std::cout << "[SUCCESS] " << _target << " has been successfully robotomized!" << std::endl;
	} else {
		std::cout << "[FAILURE] Robotomy procedure failed on " << _target << ". Subject remains organic." << std::endl;
	}
}
