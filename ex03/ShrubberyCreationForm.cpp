#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm parametric constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Execute action
void ShrubberyCreationForm::executeAction() const {
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	
	if (!file.is_open()) {
		std::cerr << "[ERROR] Failed to create output file: " << filename << std::endl;
		return;
	}

	// Pine tree with custom ASCII design
	file << "          @" << std::endl;
	file << "         <+>" << std::endl;
	file << "        <<*>>" << std::endl;
	file << "       <<<o>>>" << std::endl;
	file << "      <<<<+>>>>" << std::endl;
	file << "     <<<<<*>>>>>" << std::endl;
	file << "    <<<<<<o>>>>>>" << std::endl;
	file << "   <<<<<<<@>>>>>>>" << std::endl;
	file << "  <<<<<<<<+>>>>>>>>" << std::endl;
	file << "        [|||]" << std::endl;
	file << "        [|||]" << std::endl;
	file << "       ^^^^^^^" << std::endl;
	
	file.close();
	std::cout << "[SHRUBBERY] ASCII tree planted successfully in: " << filename << std::endl;
}
